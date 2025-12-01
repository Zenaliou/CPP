#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *test = new Bureaucrat();
	
	try
	{
		{
			test->incrementGrade();
		}
	}
	catch(Bureaucrat::GradeTooHighExceptions &e)
	{
		std::cerr << "Incrementing grade of " << test->getName() << " failed: " << e.what() << std::endl;
	}

	std::cout << *test << std::endl;

	try
	{
		test->decrementGrade();
	}
	catch(Bureaucrat::GradeTooLowExceptions &e)
	{
		std::cerr << "Decrementing grade of " << test->getName() << " failed: " << e.what() << std::endl;
	}

	std::cout << *test << std::endl;

	delete test;
	
	
}