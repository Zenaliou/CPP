#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

// Concrete form: grants presidential pardon
// Required grades: sign=25, exec=5 (hardest form - needs top bureaucrats)
class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;  // Who receives the pardon

    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        virtual ~PresidentialPardonForm();

        // Override: announces pardon by Zaphod Beeblebrox
        virtual void execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;
};

#endif