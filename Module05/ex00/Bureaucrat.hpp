#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        // Name is const because a bureaucrat's name should never change
        const std::string _name;
        // Grade range: 1 (highest) to 150 (lowest)
        size_t _grade;
        // Private setter to centralize grade validation
        void setGrade(int grade);

    public:
        // Orthodox Canonical Form: default, copy, assignment, destructor
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat(const std::string name, int grade);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // Grade modifiers - increment means better grade (lower number)
        void incrementGrade(void);
        void decrementGrade(void);

        // Getters
        const std::string getName(void)const;
        size_t getGrade(void)const;

        // Nested exception classes inheriting from std::exception
        // This allows catching them with catch(std::exception&)
        class GradeTooLowExceptions : public std::exception
        {
            public:
                // Override what() to return custom error message
                // throw() specifier indicates this function won't throw
                virtual const char *what() const throw();
        };

        class GradeTooHighExceptions : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

// Overload << operator for easy printing (outside class)
std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif