#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	try
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test exception: Span full ===" << std::endl;
	try
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		sp.addNumber(4);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test exception: not enough numbers ===" << std::endl;
	try
	{
		Span sp(5);
		sp.addNumber(42);
		std::cout << sp.shortestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test with 10000 numbers ===" << std::endl;
	try
	{
		Span bigSpan(10000);
		std::srand(std::time(NULL));

		for (int i = 0; i < 10000; i++)
			bigSpan.addNumber(std::rand());

		std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Test addNumbers with range ===" << std::endl;
	try
	{
		Span sp(10);
		std::vector<int> vec;
		vec.push_back(5);
		vec.push_back(3);
		vec.push_back(9);
		vec.push_back(1);
		vec.push_back(7);

		sp.addNumbers(vec.begin(), vec.end());

		std::cout << "Size: " << sp.getSize() << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
