#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error: no input" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pm(ac, av);

		pm.displayBefore();

		clock_t startVec = clock();
		pm.sortVector();
		clock_t endVec = clock();

		pm.displayAfter();

		clock_t startDeq = clock();
		pm.sortDeque();
		clock_t endDeq = clock();

		double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
		double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

		std::cout << "Time to process a range of " << ac - 1
				  << " elements with std::vector : " << timeVec << " us" << std::endl;
		std::cout << "Time to process a range of " << ac - 1
				  << " elements with std::deque  : " << timeDeq << " us" << std::endl;
		std::cout << "Comparisons with std::vector : " << pm.getCmpVector() << std::endl;
		std::cout << "Comparisons with std::deque  : " << pm.getCmpDeque() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
