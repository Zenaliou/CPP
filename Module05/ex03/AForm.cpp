#include "AForm.hpp"

AForm::AForm(void): _name("default"), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "AForm Default constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other.getName() + "_copy"), _is_signed(false), _sign_grade(other.getSignGrade()), _exec_grade(other.getExecGrade())
{
    std::cout << "AForm Copy Constructor called to copy " << other.getName() << " into " << this->getName() << std::endl;
    *this = other;
}

AForm::AForm(int sign_grade, int exec_grade) : _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "AForm Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
    if (sign_grade > 150 || exec_grade > 150)
        throw(AForm::GradeTooLowException());
    else if (sign_grade < 1 || exec_grade < 1)
        throw(AForm::GradeTooHighException());
}

AForm::AForm(const std::string name) : _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
    std::cout << "AForm Constructor called for " << this->getName() << std::endl;
}

AForm::AForm(const std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
    std::cout << "AForm Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and exec-grade of " << exec_grade << std::endl;
    if (sign_grade > 150 || exec_grade > 150)
        throw(AForm::GradeTooLowException());
    else if (sign_grade < 1 || exec_grade < 1)
        throw(AForm::GradeTooHighException());
}

AForm &AForm::operator=(const AForm& other)
{
    std::cout << "AForm Assignation operator called" << std::endl;
    if (this != &other)
        this->_is_signed = other._is_signed;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm Destructor for " << this->getName() << " called" << std::endl;
}

void AForm::beSigned(Bureaucrat &signer)
{
    if ((int)signer.getGrade() > this->getSignGrade())
        throw(AForm::GradeTooLowException());
    else if (this->_is_signed == false)
    {
        this->_is_signed = true;
        std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
    }
    else
        std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string AForm::getName(void) const
{
    return (this->_name);
}

const std::string AForm::getIsSigned(void) const
{
    return (this->_is_signed ? "true" : "false");
}

bool AForm::getIsSignedBool(void) const
{
    return (this->_is_signed);
}

int AForm::getSignGrade(void) const
{
    return (this->_sign_grade);
}

int AForm::getExecGrade(void) const
{
    return (this->_exec_grade);
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
    return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
    return ("Grade too high");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
    return ("Form not signed");
}

std::ostream &operator<<(std::ostream &o, const AForm &a)
{
    o << "Form " << a.getName() << " (signed: " << a.getIsSigned() 
      << ", sign grade: " << a.getSignGrade() 
      << ", exec grade: " << a.getExecGrade() << ")";
    return o;
}