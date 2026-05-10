#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

// ============================================================
//  BitcoinExchange — ex00
//
//  Lit un fichier CSV de référence (data.csv) contenant
//  l'historique des prix du Bitcoin au format :
//      date,exchange_rate
//      2009-01-02,0
//      2010-03-31,0.0498
//      ...
//
//  Puis lit un fichier d'entrée au format :
//      date | value
//      2011-01-03 | 3
//      2012-01-11 | 1.5
//
//  Pour chaque ligne valide, affiche :
//      2011-01-03 => 3 = 9.3         (date => BTC * taux = résultat)
//
//  Règles de validation :
//    - date au format YYYY-MM-DD, dans la plage [2009-2025]
//    - valeur dans ]0 ; 1000]
//    - si la date exacte n'existe pas dans la DB, on prend
//      la date la plus proche INFÉRIEURE (lower_bound - 1)
// ============================================================

#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
	// Clé   : date "YYYY-MM-DD" (tri lexicographique = tri chronologique)
	// Valeur: taux de change en USD pour 1 BTC à cette date
	// Exemple : _database["2011-01-03"] = 0.31f
	std::map<std::string, float> _database;

	// Copie et affectation désactivées (Orthodox Canonical Form)
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);

	// Vérifie que `date` respecte "YYYY-MM-DD" et que le jour est
	// cohérent avec le mois (ex: 2012-02-29 valide car 2012 est bissextile)
	bool isValidDate(const std::string& date) const;

	// Tente de convertir `valueStr` en float via strtod.
	// Retourne false si la chaîne contient des caractères non numériques.
	// Exemple : "1.5"  → value = 1.5f, retourne true
	//           "abc"  →               retourne false
	bool isValidValue(const std::string& valueStr, float& value) const;

	// Cherche le taux pour `date` dans _database.
	// Si la date exacte n'existe pas, utilise lower_bound pour trouver
	// l'entrée immédiatement antérieure (= prix le plus récent connu).
	// Lève DatabaseException si aucune entrée antérieure n'existe.
	float getExchangeRate(const std::string& date) const;

	// Supprime les espaces/tabulations en début et fin de chaîne.
	// Exemple : "  2011-01-03 " → "2011-01-03"
	std::string trim(const std::string& str) const;

public:
	BitcoinExchange();
	~BitcoinExchange();

	// Charge data.csv dans _database.
	// Ignore la ligne d'en-tête ("date,exchange_rate").
	// Lève DatabaseException si le fichier est introuvable ou vide.
	void loadDatabase(const std::string& filename);

	// Lit le fichier d'entrée ligne par ligne.
	// Pour chaque ligne valide affiche : date => value = résultat
	// Pour chaque ligne invalide affiche un message d'erreur sur stderr.
	void processInputFile(const std::string& filename);

	// Exception personnalisée pour les erreurs de chargement de la DB.
	// Usage : throw BitcoinExchange::DatabaseException("message");
	class DatabaseException : public std::exception
	{
	private:
		std::string _msg;
	public:
		DatabaseException(const std::string& msg) : _msg(msg) {}
		virtual ~DatabaseException() throw() {}
		virtual const char* what() const throw() { return _msg.c_str(); }
	};
};

#endif
