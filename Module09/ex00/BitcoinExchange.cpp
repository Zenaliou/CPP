#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	_database = other._database;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		_database = other._database;
	return *this;
}

//  trim
//  Retire les whitespaces en début/fin de chaîne.
//  Exemple :
//    trim("  2011-01-03 \r\n") → "2011-01-03"
//    trim("   ")               → ""
std::string BitcoinExchange::trim(const std::string& str) const
{
	size_t first = str.find_first_not_of(" \t\r\n");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t\r\n");
	return str.substr(first, last - first + 1);
}

//  isValidDate
//  Vérifie le format YYYY-MM-DD et la cohérence calendaire.
//
//  Exemples valides   : "2011-01-03", "2012-02-29" (bissextile)
//  Exemples invalides : "2001-42-42", "2011-1-3", "abcd-ef-gh"
//                       "2012-02-30" (fév. n'a pas 30 jours)
bool BitcoinExchange::isValidDate(const std::string& date) const
{
	// La date doit faire exactement 10 caractères : "YYYY-MM-DD"
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;

	// Tous les autres caractères doivent être des chiffres
	for (int i = 0; i < 10; i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year  = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day   = atoi(date.substr(8, 2).c_str());

	// Plage acceptée : du 1er janvier 2009 (création Bitcoin) à 2025
	if (year < 2009 || year > 2025)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;

	// Nombre de jours par mois (indice 0 = janvier, 1 = février, …)
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Année bissextile : divisible par 4, sauf centenaires non divisibles par 400
	// Exemple : 2000 → bissextile, 1900 → non bissextile, 2012 → bissextile
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeap)
		daysInMonth[1] = 29;  // février a 29 jours cette année-là

	if (day > daysInMonth[month - 1])
		return false;

	return true;
}

//  isValidValue
//  Convertit une chaîne en float avec strtod.
//  Retourne false si des caractères résiduels subsistent après
//  le nombre (ex: "1.5abc" → endPtr pointe sur 'a' → false).
//
//  Exemples :
//    "3"          → value = 3.0f,   true
//    "1.2"        → value = 1.2f,   true
//    "2147483648" → value très grande, true  (dépassement > 1000 géré ailleurs)
//    "-1"         → value = -1.0f,  true     (négatif géré ailleurs)
//    "abc"        →                 false
//    ""           →                 false
bool BitcoinExchange::isValidValue(const std::string& valueStr, float& value) const
{
	std::string trimmed = trim(valueStr);
	if (trimmed.empty())
		return false;

	char* endPtr;
	double val = strtod(trimmed.c_str(), &endPtr);

	// endPtr doit pointer sur '\0' : tous les caractères ont été consommés
	if (*endPtr != '\0')
		return false;

	value = static_cast<float>(val);
	return true;
}

//  getExchangeRate
//  Cherche le taux BTC/USD pour une date donnée.
//
//  Algorithme :
//    1. Cherche la date exacte dans _database (find).
//    2. Si absente, lower_bound renvoie l'itérateur sur la
//       première entrée >= date. On recule d'un cran (--it)
//       pour obtenir la dernière entrée < date.
//    3. Si on est au début de la map, aucune donnée antérieure
//       n'existe → exception.
//
//  Exemple (avec _database = {2009-01-02:0, 2011-01-03:0.31}) :
//    getExchangeRate("2011-01-03") → 0.31  (trouvé directement)
//    getExchangeRate("2011-01-05") → 0.31  (2011-01-03 est la plus proche)
//    getExchangeRate("2009-01-01") → exception (avant toute entrée)
float BitcoinExchange::getExchangeRate(const std::string& date) const
{
	std::map<std::string, float>::const_iterator it = _database.find(date);

	if (it != _database.end())
		return it->second;  // Date exacte trouvée

	// lower_bound("2011-01-05") pointe sur la première clé >= "2011-01-05"
	it = _database.lower_bound(date);
	if (it == _database.begin())
		throw DatabaseException("Error: no data available for this date.");
	--it;  // Recule sur la dernière clé strictement inférieure à date
	return it->second;
}

//  loadDatabase
//  Charge data.csv dans _database.
//
//  Format attendu (séparateur virgule) :
//      date,exchange_rate
//      2009-01-02,0
//      2010-07-17,0.0498
//      2011-01-03,0.31
//
//  La première ligne (en-tête) est ignorée.
//  Les lignes malformées (pas de virgule, valeur non numérique)
//  sont silencieusement ignorées.
void BitcoinExchange::loadDatabase(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw DatabaseException("Error: could not open database file.");

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		if (firstLine)
		{
			firstLine = false;
			continue; // Ignore l'en-tête "date,exchange_rate"
		}

		if (line.empty())
			continue;

		// Sépare la ligne sur la virgule
		// Exemple : "2011-01-03,0.31" → date="2011-01-03", rateStr="0.31"
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date    = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		float rate;
		if (!isValidValue(rateStr, rate))
			continue;

		_database[date] = rate;  // Insertion ou mise à jour
	}

	file.close();

	if (_database.empty())
		throw DatabaseException("Error: database is empty or invalid.");
}

//  processInputFile
//  Lit le fichier d'entrée (argv[1]) et affiche les résultats.
//
//  Format attendu (séparateur " | ") :
//      date | value
//      2011-01-03 | 3
//      2012-01-11 | 1.5
//
//  Sorties possibles pour chaque ligne :
//    OK      → "2011-01-03 => 3 = 0.93"
//    date invalide          → "Error: bad input => 2001-42-42"
//    valeur non numérique   → "Error: bad input => abc"
//    valeur négative        → "Error: not a positive number."
//    valeur > 1000          → "Error: too large a number."
//    pas de données en DB   → "Error: no data available for this date."
void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	bool firstLine = true;

	while (std::getline(file, line))
	{
		// ── Première ligne : vérification de l'en-tête ──────────────────
		// Le fichier d'entrée DOIT commencer par exactement "date | value".
		if (firstLine)
		{
			firstLine = false;
			std::string trimmedLine = trim(line);
			if (trimmedLine != "date | value")
			{
				std::cerr << "Error: invalid file header." << std::endl;
				file.close();
				return;
			}
			continue;
		}

		if (line.empty())
			continue;

		// ── Découpe sur le séparateur '|' ───────────────────────────────
		// Exemple : "2011-01-03 | 3" → date="2011-01-03", valueStr="3"
		// Exemple malformé : "2011-01-03" (pas de '|') → erreur
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date     = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		// ── Validation de la date ────────────────────────────────────────
		// Exemple invalide : "2001-42-42" → mois 42 inexistant
		if (!isValidDate(date))
		{
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}

		// ── Validation de la valeur ──────────────────────────────────────
		// Exemple invalide : "abc", "1.2.3"
		float value;
		if (!isValidValue(valueStr, value))
		{
			std::cerr << "Error: bad input => " << valueStr << std::endl;
			continue;
		}

		// La valeur doit être strictement positive
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}

		// On accepte au maximum 1000 BTC par transaction
		if (value > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}

		// ── Calcul et affichage ─────────────────────────────────────────
		// Exemple : date="2011-01-03", value=3, rate=0.31
		//           → "2011-01-03 => 3 = 0.93"
		try
		{
			float rate   = getExchangeRate(date);
			float result = value * rate;
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
		catch (const std::exception& e)
		{
			// getExchangeRate peut lever DatabaseException si la date
			// est antérieure à toute entrée de la base
			std::cerr << e.what() << std::endl;
		}
	}

	file.close();
}
