#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}


bool RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

//  applyOperator
//  Dépile deux opérandes et applique l'opérateur `op`.
//
//  Ordre important :
//    La pile est LIFO, donc le dernier empilé est le membre
//    DROIT de l'expression.
//
//    Pile avant : [..., a, b]   (b est au sommet = top)
//    Après pop b, pop a → calcule (a OP b)
//
//  Exemple pour "5 3 -" :
//    Après avoir empilé 5 puis 3 : pile = [5, 3]
//    b = pop() = 3
//    a = pop() = 5
//    résultat = 5 - 3 = 2   ✓  (et NON 3 - 5 = -2)
//
//  Cas d'erreur gérés :
//    - Moins de 2 éléments dans la pile → expression invalide
//    - Division par zéro → erreur explicite
bool RPN::applyOperator(char op)
{
	// Il faut au minimum 2 opérandes pour appliquer un opérateur binaire
	if (_stack.size() < 2)
	{
		std::cerr << "Error: not enough operands for operator '" << op << "'" << std::endl;
		return false;
	}

	// Dépiler dans l'ordre correct
	int b = _stack.top(); _stack.pop();  // opérande DROIT  (dernier empilé)
	int a = _stack.top(); _stack.pop();  // opérande GAUCHE (avant-dernier)

	int result = 0;

	switch (op)
	{
		case '+': result = a + b; break;
		case '-': result = a - b; break;
		case '*': result = a * b; break;
		case '/':
			if (b == 0)
			{
				std::cerr << "Error: division by zero" << std::endl;
				return false;
			}
			result = a / b;
			break;
		default:
			// Ne devrait jamais arriver car on appelle isOperator() avant
			std::cerr << "Error: unknown operator '" << op << "'" << std::endl;
			return false;
	}

	// Empiler le résultat intermédiaire pour la suite de l'évaluation
	_stack.push(result);
	return true;
}

//  evaluate
//  Parcourt l'expression token par token et utilise la pile
//  pour évaluer le résultat final.
//
//  Algorithme (Dijkstra – Shunting-yard simplifié pour RPN) :
//    Pour chaque token séparé par un espace :
//      - chiffre unique (0–9) → push sur la pile
//      - opérateur (+,-,*,/) → applyOperator()
//      - autre → erreur
//    Vérifier qu'il reste exactement 1 élément dans la pile.
//
//  Exemples complets :
//    "8 9 * 9 - 9 - 9 - 4 - 1 +"  → 42
//    "7 7 * 7 -"                   → 42
//    "1 2 * 2 / 2 * 2 4 - +"       → 0
//    "3 4 +"                       → 7
//    "(1 + 1)"                     → Error  (parenthèses non supportées)
//    "10 2 +"                      → Error  (10 n'est pas un chiffre simple)
bool RPN::evaluate(const std::string& expression)
{
	// Réinitialiser la pile au cas où evaluate() serait appelé plusieurs fois
	while (!_stack.empty())
		_stack.pop();

	// Utiliser un flux pour découper l'expression par espaces
	std::istringstream stream(expression);
	std::string token;

	while (stream >> token)
	{
		// Cas 1 : le token est un chiffre unique (0–9)
		//   - Un chiffre simple a exactement 1 caractère ET est numérique
		//   - "12" est INVALIDE selon le sujet (multi-chiffres non supportés)
		if (token.length() == 1 && std::isdigit(token[0]))
		{
			// Convertir le caractère chiffre en entier et empiler
			// Exemple : '7' → 7  (via soustraction de '0')
			_stack.push(token[0] - '0');
		}
		// Cas 2 : le token est un opérateur
		else if (token.length() == 1 && isOperator(token[0]))
		{
			if (!applyOperator(token[0]))
				return false;
		}
		// Cas 3 : token invalide (multi-chiffres, parenthèses, caractère inconnu…)
		else
		{
			std::cerr << "Error: invalid token '" << token << "'" << std::endl;
			return false;
		}
	}

	// Après avoir traité tous les tokens, la pile doit contenir EXACTEMENT
	// un élément : le résultat final.
	// Si elle est vide → expression vide.
	// Si elle contient plus d'un élément → trop d'opérandes, pas assez d'opérateurs.
	if (_stack.size() != 1)
	{
		std::cerr << "Error: invalid expression (too many operands)" << std::endl;
		return false;
	}

	// Afficher le résultat final
	std::cout << _stack.top() << std::endl;
	return true;
}
