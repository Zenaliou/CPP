#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
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