#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

class Intern
{
    public:
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        AForm *makeForm(const std::string formName, const std::string target);

    private:
        AForm *makeShrubbery(const std::string target);
        AForm *makeRobotomy(const std::string target);
        AForm *makePresidential(const std::string target);
};

#endif