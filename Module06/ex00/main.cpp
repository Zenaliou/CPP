#include "Conversion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert <literal>" << std::endl;
		return (1);
	}
	
	std::string input(av[1]);
	Conversion::Convert(input);
	
	return (0);
}