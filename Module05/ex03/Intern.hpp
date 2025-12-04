#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

// Intern class: Factory pattern for creating forms
// No name, no grade, no unique characteristics - just makes forms
class Intern
{
    public:
        // Orthodox Canonical Form (even though Intern has no attributes)
        Intern(void);
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();

        // Factory method: creates appropriate form based on formName string
        // Returns pointer to newly allocated form (caller must delete)
        // Returns NULL if formName is unknown
        AForm *makeForm(const std::string formName, const std::string target);

    private:
        // Private helper methods - one for each form type
        // These are used via function pointers to avoid if/else chains
        AForm *makeShrubbery(const std::string target);
        AForm *makeRobotomy(const std::string target);
        AForm *makePresidential(const std::string target);
};

#endif