#include "Zombie.hpp"

int main() 
{
    int N = 5;
    std::string name = "Niclee";
    
    std::cout << "Creating a horde of " << N << " zombies named " << name << std::endl;
    
    Zombie* horde = zombieHorde(N, name);
    
    if (horde) 
	{
        for (int i = 0; i < N; i++) 
		{
            std::cout << "Zombie " << i + 1 << ": ";
            horde[i].announce();
        }
        std::cout << "\nDestroying the horde..." << std::endl;
        delete[] horde;
    }
    return (0);
}
