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

// Private helper: creates ShrubberyCreationForm
// Returns dynamically allocated form (caller responsible for deletion)
AForm *Intern::makeShrubbery(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

// Private helper: creates RobotomyRequestForm
AForm *Intern::makeRobotomy(const std::string target)
{
    return new RobotomyRequestForm(target);
}

// Private helper: creates PresidentialPardonForm
AForm *Intern::makePresidential(const std::string target)
{
    return new PresidentialPardonForm(target);
}

// Factory method: creates form based on name string
// Uses array of function pointers to avoid long if/else chain
// This approach is more scalable and easier to maintain
AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    // Array of valid form names (must match order of formCreators)
    std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    // Array of member function pointers
    // Syntax: ReturnType (ClassName::*pointerName)(Parameters)
    // Each points to a private helper method that creates specific form
    AForm *(Intern::*formCreators[])(const std::string) = {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };

    // Search for matching form name
    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            // Call member function through pointer
            // Syntax: (object.*memberFunctionPointer)(arguments)
            return (this->*formCreators[i])(target);
        }
    }
    
    // Form name not found
    std::cout << "Intern cannot create form: " << formName << " (unknown form)" << std::endl;
    return NULL;
}