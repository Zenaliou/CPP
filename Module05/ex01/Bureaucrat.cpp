#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(150)
{
	std::cout << "Bureaucrat constructor called for " << this->getName() << " with grade of " << grade << std::endl;
	this->setGrade(grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Bureaucrat assignement operator called" << std::endl;

	if (this != &other)
    {
        _grade = other._grade;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called for " << this->getName() << std::endl;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "Incrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "Decrementing grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

const std::string Bureaucrat::getName(void)const
{
	return (this->_name);
}

size_t Bureaucrat::getGrade(void)const
{
	return (this->_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowExceptions();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighExceptions();
	else
		this->_grade = grade;
}

const char *Bureaucrat::GradeTooHighExceptions::what(void) const throw()
{
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowExceptions::what(void) const throw()
{
	return ("Grade too low");
}

void Bureaucrat::signForm(Form &form)
{
    try
    {
        // Attempt to sign - may throw if grade insufficient
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        // Catch and report failure with reason
        std::cout << this->getName() << " couldn't sign " << form.getName() 
            << " because " << e.what() << std::endl;
    }
}

