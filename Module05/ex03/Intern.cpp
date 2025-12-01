#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern copy constructor called" << std::endl;
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    std::cout << "Intern assignation operator called" << std::endl;
    (void)other;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidential(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    AForm *(Intern::*formCreators[])(const std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern cannot create form: " << formName << " (unknown form)" << std::endl;
    return NULL;
}