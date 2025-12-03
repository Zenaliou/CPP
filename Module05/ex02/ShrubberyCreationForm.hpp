#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>  // For file operations

// Concrete form: creates ASCII tree in a file
// Required grades: sign=145, exec=137 (easiest form)
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;  // Filename prefix for output

    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        virtual ~ShrubberyCreationForm();

        // Override pure virtual: writes ASCII trees to <target>_shrubbery file
        virtual void execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;
};

#endif