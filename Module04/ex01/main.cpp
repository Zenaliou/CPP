#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
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
    {
        Dog tmp = basic;
    }
    
    return 0;
}