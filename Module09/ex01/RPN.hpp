#ifndef RPN_HPP
#define RPN_HPP

//  RPN — ex01 (Reverse Polish Notation Calculator)
//
//  La Notation Polonaise Inversée (NPI) est une façon d'écrire
//  des expressions mathématiques SANS parenthèses, où l'opérateur
//  est placé APRÈS ses opérandes.
//
//  Exemples de conversion :
//    Notation classique :  3 + 4          → RPN : 3 4 +
//    Notation classique :  (3 + 4) * 2    → RPN : 3 4 + 2 *
//    Notation classique :  8 * 9 - 9 - …  → RPN : 8 9 * 9 - …
//
//  Comment évaluer une expression RPN avec une pile (stack) :
//    1. Lire les tokens (séparés par des espaces) de gauche à droite
//    2. Si c'est un CHIFFRE (0–9)  → empiler (push)
//    3. Si c'est un OPÉRATEUR (+, -, *, /) :
//         - dépiler (pop) deux opérandes : b (top) puis a
//         - calculer (a OP b)
//         - empiler le résultat
//    4. À la fin, la pile doit contenir exactement UN élément : le résultat
//
//  Exemple pas-à-pas pour "3 4 + 2 *" :
//    Token "3" → pile : [3]
//    Token "4" → pile : [3, 4]
//    Token "+" → b=4, a=3, résultat=7 → pile : [7]
//    Token "2" → pile : [7, 2]
//    Token "*" → b=2, a=7, résultat=14 → pile : [14]
//    Résultat final : 14
//
//  Contraintes du sujet :
//    - Les nombres dans l'expression sont des chiffres SIMPLES (0–9)
//    - Le résultat peut dépasser 9 (pas de limite de taille)
//    - Division par zéro → erreur
//    - Expression invalide → "Error" sur stderr
//    - Un seul argument en ligne de commande (entre guillemets)

#include <string>
#include <stack>
#include <iostream>
#include <sstream>

class RPN
{
	private:
		// La pile stocke les entiers intermédiaires pendant l'évaluation.
		// Exemple après "3 4 +" : _stack contient [7]
		std::stack<int> _stack;

		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

		// Applique l'opérateur `op` sur les deux valeurs au sommet de la pile.
		bool applyOperator(char op);

		bool isOperator(char c) const;

	public:
		RPN();
		~RPN();

		// Évalue l'expression RPN passée en argument.
		// Affiche le résultat sur stdout.
		// Affiche "Error" sur stderr et retourne false en cas d'erreur.
		// Retourne true si l'évaluation s'est déroulée sans erreur.
		bool evaluate(const std::string& expression);
};

#endif
