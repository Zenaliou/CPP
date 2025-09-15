#include "phonebook.hpp"

Phonebook::Phonebook() : currentIndex(0), totalContacts(0)
{
}

Phonebook::~Phonebook()
{
}

void	Phonebook::addContact()
{
	std::string input;

	std::cout << "Entrez le prénom: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Le prénom ne peut pas être vide!" << std::endl;
		return;
	}
	contacts[currentIndex].setName(input);

	std::cout << "Entrez le nom de famille: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Le nom de famille ne peut pas être vide!" << std::endl;
		return;
	}
	contacts[currentIndex].setLast(input);

	std::cout << "Entrez le surnom: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Le surnom ne peut pas être vide!" << std::endl;
		return;
	}
	contacts[currentIndex].setNick(input);

	std::cout << "Entrez le numéro de téléphone: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Le numéro de téléphone ne peut pas être vide!" << std::endl;
		return;
	}
	contacts[currentIndex].setPhone(input);

	std::cout << "Entrez le secret: ";
	std::getline(std::cin, input);
	if (input.empty())
	{
		std::cout << "Le secret ne peut pas être vide!" << std::endl;
		return;
	}
	contacts[currentIndex].setSecret(input);

	std::cout << "Contact ajouté avec succès!" << std::endl;
	
	currentIndex = (currentIndex + 1) % max;
	if (totalContacts < max)
		totalContacts++;
}

void	Phonebook::searchContact()
{

}

void	Phonebook::displayContacts()
{
	std::string field;
	
	if (totalContacts == 0)
	{
		std::cout << "Aucun contact dans le répertoire!" << std::endl;
		return;
	}

	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "Prénom" << "|";
	std::cout << std::setw(10) << "Nom" << "|";
	std::cout << std::setw(10) << "Surnom" << std::endl;
	std::cout << "----------------------------------------" << std::endl;

	for (int i = 0; i < totalContacts; i++)
	{
		std::cout << std::setw(10) << i << "|";
		
		// Prénom
		field = contacts[i].getName();
		if (field.length() > 10)
			field = field.substr(0, 9) + ".";
		std::cout << std::setw(10) << field << "|";
		
		// Nom
		field = contacts[i].getLast();
		if (field.length() > 10)
			field = field.substr(0, 9) + ".";
		std::cout << std::setw(10) << field << "|";
		
		// Surnom
		field = contacts[i].getNick();
		if (field.length() > 10)
			field = field.substr(0, 9) + ".";
		std::cout << std::setw(10) << field << std::endl;
	}
}

void	Phonebook::displayContactDetails(int index)
{
	if (index < 0 || index >= totalContacts)
	{
		std::cout << "Index invalide!" << std::endl;
		return;
	}

	std::cout << "===== DÉTAILS DU CONTACT =====" << std::endl;
	std::cout << "Prénom: " << contacts[index].getName() << std::endl;
	std::cout << "Nom: " << contacts[index].getLast() << std::endl;
	std::cout << "Surnom: " << contacts[index].getNick() << std::endl;
	std::cout << "Téléphone: " << contacts[index].getPhone() << std::endl;
	std::cout << "Secret: " << contacts[index].getSecret() << std::endl;
	std::cout << "===============================" << std::endl;
}