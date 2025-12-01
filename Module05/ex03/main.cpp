#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    std::cout << "=== Test ShrubberyCreationForm ===" << std::endl;
    try
    {
        Bureaucrat bob("Bob", 140);
        ShrubberyCreationForm shrub("garden");
        
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test RobotomyRequestForm ===" << std::endl;
    try
    {
        Bureaucrat alice("Alice", 40);
        RobotomyRequestForm robot("Bender");
        
        std::cout << robot << std::endl;
        alice.signForm(robot);
        alice.executeForm(robot);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test PresidentialPardonForm ===" << std::endl;
    try
    {
        Bureaucrat president("President", 1);
        PresidentialPardonForm pardon("Arthur Dent");
        
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test Execution Without Signing ===" << std::endl;
    try
    {
        Bureaucrat charlie("Charlie", 1);
        PresidentialPardonForm pardon2("Ford Prefect");
        
        charlie.executeForm(pardon2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test Grade Too Low to Execute ===" << std::endl;
    try
    {
        Bureaucrat lowGrade("LowGrade", 150);
        Bureaucrat highGrade("HighGrade", 1);
        RobotomyRequestForm robot2("Target");
        
        highGrade.signForm(robot2);
        lowGrade.executeForm(robot2);
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test Intern ===" << std::endl;
    {
        Intern someRandomIntern;
        AForm *form;

        form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }

        form = someRandomIntern.makeForm("shrubbery creation", "home");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }

        form = someRandomIntern.makeForm("presidential pardon", "Ford");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }

        form = someRandomIntern.makeForm("unknown form", "target");
        if (!form)
            std::cout << "Form creation failed as expected" << std::endl;
    }

    return 0;
}