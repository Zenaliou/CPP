#include "RPN.hpp"

//  main — RPN Calculator
//
//  Usage : ./RPN "<expression>"
//
//  L'expression RPN est passée en UN SEUL argument (entre
//  guillemets dans le shell pour préserver les espaces).
//
//  Exemples d'utilisation :
//    $ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
//    42
//
//    $ ./RPN "7 7 * 7 -"
//    42
//
//    $ ./RPN "1 2 * 2 / 2 * 2 4 - +"
//    0
//
//    $ ./RPN "3 4 +"
//    7
//
//    $ ./RPN "5 1 2 + 4 * + 3 -"
//    14
//    Vérification : (1+2)=3 → 3*4=12 → 5+12=17 → 17-3=14  ✓
//
//    $ ./RPN "(1 + 1)"
//    Error: invalid token '(1'
//
//    $ ./RPN "3 +"
//    Error: not enough operands for operator '+'
//
//    $ ./RPN "3 0 /"
//    Error: division by zero
//
//  Étapes :
//    1. Vérifier qu'exactement un argument est fourni.
//    2. Instancier RPN et appeler evaluate() avec l'argument.
//    3. Retourner 0 si succès, 1 si erreur.

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"" << std::endl;
		std::cerr << "Example: " << argv[0] << " \"3 4 + 2 *\"" << std::endl;
		return 1;
	}

	RPN calculator;

	if (!calculator.evaluate(argv[1]))
		return 1;

	return 0;
}
