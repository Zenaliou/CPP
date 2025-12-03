#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("default")
{
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
    std::cout << "RobotomyRequestForm constructor called for target: " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm assignation operator called" << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getTarget(void) const
{
    return this->_target;
}

// Makes drilling noises, then 50% chance of success
void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getIsSignedBool())
        throw AForm::FormNotSignedException();
    if ((int)executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    // Drilling sound effect
    std::cout << "* DRILLING NOISES * Bzzzzz..." << std::endl;
    
    // 50% success rate using random number
    srand(time(NULL));  // Seed with current time
    if (rand() % 2)     // rand() % 2 gives 0 or 1
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << this->_target << "!" << std::endl;
}