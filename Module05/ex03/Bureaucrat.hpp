#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
    private:
        const std::string _name;
        size_t _grade;
        void setGrade(int grade);

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(AForm &form);
        void executeForm(AForm const &form);

        const std::string getName(void) const;
        size_t getGrade(void) const;

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
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif