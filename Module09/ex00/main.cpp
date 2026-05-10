#include "BitcoinExchange.hpp"

// ============================================================
//  main — Bitcoin Exchange
//
//  Usage : ./btc <input_file>
//
//  Exemple :
//    $ ./btc input.txt
//    2011-01-03 => 3 = 0.93
//    2011-01-03 => 2 = 0.62
//    2011-01-03 => 1 = 0.31
//    2011-01-03 => 1.2 = 0.372
//    2011-01-09 => 1 = 0.31
//    Error: not a positive number.
//    Error: bad input => 2001-42-42
//    2012-01-11 => 1 = 7.1
//    Error: too large a number.
//
//  Étapes :
//    1. Vérifier qu'un seul argument est fourni.
//    2. Charger data.csv dans la map interne de BitcoinExchange.
//    3. Lire le fichier d'entrée ligne par ligne et afficher
//       le résultat de la conversion pour chaque ligne valide.
// ============================================================

int main(int argc, char** argv)
{
	// Le programme attend exactement un argument : le fichier d'entrée
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	try
	{
		// Charge l'historique des prix depuis data.csv
		btc.loadDatabase("data.csv");

		// Traite le fichier passé en argument (ex: input.txt)
		btc.processInputFile(argv[1]);
	}
	catch (const std::exception& e)
	{
		// loadDatabase peut lever DatabaseException si data.csv
		// est introuvable ou vide
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
