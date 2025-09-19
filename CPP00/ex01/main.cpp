#include "phonebook.hpp"

int main(void)
{
	Phonebook phonebook;
	std::string command;

	std::cout << "====== RÉPERTOIRE TÉLÉPHONIQUE ======" << std::endl;
	std::cout << "Commandes disponibles:" << std::endl;
	std::cout << "  ADD    - Ajouter un nouveau contact" << std::endl;
	std::cout << "  SEARCH - Rechercher un contact" << std::endl;
	std::cout << "  EXIT   - Quitter le programme" << std::endl;
	std::cout << "=====================================" << std::endl;

	while (true)
	{
		std::cout << std::endl << "Entrez une commande: ";
		std::getline(std::cin, command);

		if (std::cin.eof())
		{
			std::cout << std::endl << "Au revoir!" << std::endl;
			break;
		}

		if (command == "ADD")
			phonebook.addContact();
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
		{
			std::cout << "Au revoir!" << std::endl;
			break;
		}
		else
			std::cout << "Commande invalide! Utilisez ADD, SEARCH ou EXIT." << std::endl;
	}
	return (0);
}
