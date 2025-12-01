#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== Test Bureaucrat ==="<< std::endl;
	Bureaucrat *bob = new Bureaucrat("Bob", 50);
	Bureaucrat *alice = new Bureaucrat("Alice", 1);
	
	std::cout << "\n=== Test Form Creation ==="<< std::endl;
	try
	{
		Form formA("FormA", 45, 30);
		std::cout << formA << std::endl;
		
		Form formB("FormB", 5, 3);
		std::cout << formB << std::endl;
		
		std::cout << "\n=== Test Signing Forms ==="<< std::endl;
		bob->signForm(formA);  // Should succeed
		bob->signForm(formB);  // Should fail (grade too low)
		alice->signForm(formB); // Should succeed
		alice->signForm(formA); // Already signed
		
		std::cout << "\n=== Final Form States ==="<< std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n=== Test Invalid Form ==="<< std::endl;
	try
	{
		Form invalidForm("Invalid", 0, 50); // Should throw exception
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	
	delete bob;
	delete alice;
	
	return 0;
}