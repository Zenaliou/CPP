#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{

    std::cout << "--- Basic Tests ---" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    // Test makeSound (polymorphisme)
    std::cout << j->getType() << " says: ";
    j->makeSound();
    std::cout << i->getType() << " says: ";
    i->makeSound();
    
    delete j;
    delete i;
    
    std::cout << "\n--- Array of Animals ---" << std::endl;
    const Animal* animals[4];
    
    for (int idx = 0; idx < 2; idx++)
        animals[idx] = new Dog();
    
    for (int idx = 2; idx < 4; idx++)
        animals[idx] = new Cat();
    
    for (int idx = 0; idx < 4; idx++)
        delete animals[idx];
    
    std::cout << "\n--- Deep Copy Test ---" << std::endl;
    Dog basic;
    Dog tmp = basic;
    
    basic.getBrain()->setIdea(0, "I'm the original");
    tmp.getBrain()->setIdea(0, "I'm the copy");
    
    std::cout << "Original idea: " << basic.getBrain()->getIdea(0) << std::endl;
    std::cout << "Copy idea: " << tmp.getBrain()->getIdea(0) << std::endl;
    
    return 0;
}