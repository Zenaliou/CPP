#include "Form.hpp"

Form::Form(void): _name("default"), _is_signed(false), _sign_grade (150), _exec_grade(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other.getName() + "_copy"), _is_signed(false), _sign_grade(other.getSignGrade()), _exec_grade(other.getExecGrade())
{
	std::cout << "Form Copy Constructor called to copy " << other.getName() << " into " << this->getName() <<std::endl;
	*this = other;
}

Form::Form(int sign_grade, int exec_grade) : _name("default"), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() << "with sign-grade of " << sign_grade << " and execution-grade of " << exec_grade << std::endl;
	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 || j > 150)
		throw(Form::GradeTooLowExceptions());
	else if (i < 1 || j < 1)
		throw(Form::GradeTooHighExceptions());
}

Form::Form(const std::string name) : _name(name), _is_signed(false), _sign_grade(150), _exec_grade(150)
{
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << this ->getSignGrade() << " and execution-grade of " << this ->getExecGrade() << std::endl;
}

Form::Form(const std::string name, int sign_grade, int exec_grade) : _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	std::cout << "Form Constructor called for " << this->getName() << " with sign-grade of " << sign_grade << " and exec-grade of " << exec_grade << std::endl;

	const int i = this->getSignGrade();
	const int j = this->getExecGrade();
	if (i > 150 | j > 150)
		throw(Form::GradeTooLowExceptions());
	else if (i < 1 | j < 1)
		throw(Form::GradeTooHighExceptions());
}

Form &Form::operator=(const Form& other)
{
	std::cout << "Form Assignation operator called" << std::endl;

	if (this == &other)
		return *this;
	return *this;
}

Form::~Form()
{
	std::cout << "Form Destructor for " << this->getName() << " called" << std::endl;
}

void Form::beSigned(Bureaucrat &signer)
{
	if (((int)signer.getGrade() > this->getSignGrade()))
		throw(Bureaucrat::GradeTooLowExceptions());
	else if (this->getIsSigned() == "false")
	{
		this->_is_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
}

const std::string Form::getName(void)const
{
	return (this->_name);
}

const std::string Form::getIsSigned(void)const
{
	if (this->_is_signed)
		return ("true");
	else
		return ("false");
}

bool Form::getIsSignedBool(void)const
{
	return (this->_is_signed);
}

int Form::getSignGrade(void)const
{
	return (this->_sign_grade);
}

int Form::getExecGrade(void)const
{
	return (this->_exec_grade);
}

const char *Form::GradeTooLowExceptions::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighExceptions::what(void) const throw()
{
	return ("Grade too high");
}

std::ostream &operator<<(std::ostream &o, const Form &a)
{
	o << "Form " << a.getName() << " (signed: " << a.getIsSigned() 
	  << ", sign grade: " << a.getSignGrade() 
	  << ", exec grade: " << a.getExecGrade() << ")";
	return o;
}