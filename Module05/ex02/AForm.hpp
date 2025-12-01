#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _is_signed;
        const int _sign_grade;
        const int _exec_grade;

    public:
        AForm(void);
        AForm(const AForm &other);
        AForm(int sign_grade, int exec_grade);
        AForm(const std::string name);
        AForm(const std::string name, int sign_grade, int exec_grade);
        AForm &operator=(const AForm& other);
        virtual ~AForm();

        void beSigned(Bureaucrat &signer);
        virtual void execute(Bureaucrat const &executor) const = 0;
        
        const std::string getName(void) const;
        const std::string getIsSigned(void) const;
        bool getIsSignedBool(void) const;
        int getSignGrade(void) const;
        int getExecGrade(void) const;

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &o, const AForm &a);

#endif