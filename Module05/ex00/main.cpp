#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== Test 1: Valid bureaucrat creation ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade too high (0) ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade too low (151) ===" << std::endl;
	try
	{
		Bureaucrat invalid2("Invalid2", 151);
		std::cout << invalid2 << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment to grade 1 then try to increment again ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 2);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << alice << std::endl;
		alice.incrementGrade(); // Should throw exception
		std::cout << alice << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement to grade 150 then try to decrement again ===" << std::endl;
	try
	{
		Bureaucrat charlie("Charlie", 149);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << charlie << std::endl;
		charlie.decrementGrade(); // Should throw exception
		std::cout << charlie << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy constructor ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}