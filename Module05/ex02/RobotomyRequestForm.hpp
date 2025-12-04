#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>  // For rand(), srand()
#include <ctime>    // For time()

// Concrete form: attempts to robotomize target (50% success rate)
// Required grades: sign=72, exec=45 (medium difficulty)
class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;  // Who to robotomize

    public:
        RobotomyRequestForm(void);
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();

        // Override: makes drilling noises, 50% success
        virtual void execute(Bureaucrat const &executor) const;
        std::string getTarget(void) const;
};

#endif