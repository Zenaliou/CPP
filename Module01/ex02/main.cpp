#include <iostream>
#include <string>

int main() {
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    // Affichage des adresses mémoire
    std::cout << "Adresse de la variable string:    " << &string << std::endl;
    std::cout << "Adresse stockée dans stringPTR:   " << stringPTR << std::endl;
    std::cout << "Adresse de stringREF:             " << &stringREF << std::endl;

    std::cout << std::endl;

    // Affichage des valeurs
    std::cout << "Valeur de la variable string:     " << string << std::endl;
    std::cout << "Valeur pointée par stringPTR:     " << *stringPTR << std::endl;
    std::cout << "Valeur de stringREF:              " << stringREF << std::endl;

    return 0;
}