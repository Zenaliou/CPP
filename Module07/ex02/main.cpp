#include "Array.hpp"

#define MAX_VAL 750

int main(void)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    std::cout << "\n--- Test empty array ---" << std::endl;
    Array<int> empty;
    std::cout << "Length of empty array: " << empty.size() << std::endl;

    std::cout << "\n--- Test with strings ---" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    for (unsigned int i = 0; i < strings.size(); i++)
        std::cout << strings[i] << " ";
    std::cout << std::endl;

    std::cout << "\n--- Test assignation ---" << std::endl;
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++)
        original[i] = i * 10;

    Array<int> copy;
    copy = original;

    std::cout << "Original: ";
    for (unsigned int i = 0; i < original.size(); i++)
        std::cout << original[i] << " ";
    std::cout << std::endl;

    std::cout << "Copy: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    copy[0] = 999;
    std::cout << "After modification copy[0]:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;

    return 0;
}