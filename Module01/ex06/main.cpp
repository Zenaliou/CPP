#include "Harl.hpp"

int getLevel(std::string level)
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == level)
            return i;
    }
    return -1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./harlFilter <level>" << std::endl;
        return 1;
    }
    
    Harl harl;
    int level = getLevel(argv[1]);
    
    // Filter messages by level: displays the chosen level and all levels above it
    // Uses fall-through to create hierarchy DEBUG < INFO < WARNING < ERROR
    switch (level)
    {
        case 0: // DEBUG
            harl.complain("DEBUG");
        case 1: // INFO
            harl.complain("INFO");
        case 2: // WARNING
            harl.complain("WARNING");
        case 3: // ERROR
            harl.complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
    return 0;
}