#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

// Forward declaration to resolve circular dependency
// Form needs Bureaucrat, Bureaucrat needs Form
class Bureaucrat;

class Form
{
    private:
        // All attributes except _is_signed are const (cannot change after creation)
        const std::string _name;
        bool _is_signed;                // Only attribute that can change
        const int _sign_grade;          // Minimum grade required to sign
        const int _exec_grade;          // Minimum grade required to execute

    public:
        // Orthodox Canonical Form + additional constructors
        Form(void);
        Form(const Form &other);
        Form(int sign_grade, int exec_grade);
        Form(const std::string name);
        Form(const std::string name, int sign_grade, int exec_grade);
        Form &operator=(const Form& other);
        ~Form();

        // Main action: attempts to sign the form if bureaucrat has sufficient grade
        void beSigned(Bureaucrat &signer);

        // Getters
        const std::string getName(void)const;
        const std::string getIsSigned(void)const;  // Returns "true" or "false" string
        bool getIsSignedBool(void)const;           // Returns actual bool
        int getSignGrade(void)const;
        int getExecGrade(void)const;

        // Nested exception classes (same pattern as Bureaucrat)
        class GradeTooLowExceptions : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighExceptions : public std::exception
        {
            virtual const char *what() const throw();
        };
};

// Insertion operator for easy printing
std::ostream &operator<<(std::ostream &o, const Form &a);

#endif