#include "iter.hpp"

int printInt(int &n)
{
	std::cout << n << std::endl;
	return 0;
}

char printChar(char &s)
{
	std::cout << s << std::endl;
	return 0;
}

int main(void)
{
	char char_array[] = {'a', 'b', 'c', 'd'};
	int int_array[] = {1, 2, 3, 4};

	::iter(int_array, 4, printInt);
	::iter(char_array, 4, printChar);
}