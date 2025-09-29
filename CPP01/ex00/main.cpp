#include "Zombie.hpp"

int main()
{
	std::cout << "=== Testing heap allocation with newZombie ===" << std::endl;
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;  // Don't forget to free the memory!

	std::cout << "\n=== Testing stack allocation with randomChump ===" << std::endl;
	randomChump("StackZombie");
	
	std::cout << "\n=== End of program ===" << std::endl;
	return 0;
}
