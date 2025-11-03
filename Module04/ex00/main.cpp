#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Test with correct Animal hierarchy ===" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "\nType tests:" << std::endl;
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    std::cout << "\nSound tests:" << std::endl;
    i->makeSound(); // will output the cat sound!
    j->makeSound(); // will output the dog sound!
    meta->makeSound(); // will output generic animal sound

    std::cout << "\nDestruction:" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "\n=== Test with wrong Animal hierarchy ===" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "\nType tests:" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    std::cout << "\nSound tests:" << std::endl;
    wrongCat->makeSound(); // will NOT output the cat sound!
    wrongMeta->makeSound();

    std::cout << "\nDestruction:" << std::endl;
    delete wrongMeta;
    delete wrongCat;

    std::cout << "\n=== Additional tests ===" << std::endl;
    
    std::cout << "\nDirect WrongCat test:" << std::endl;
    WrongCat directWrongCat;
    directWrongCat.makeSound(); // This will work correctly

    return 0;
}