#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("unnamed", 72, 45), target("nobody"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), target(target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target){}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
    if(this->getSigned() == false)
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << "BRRRRRRRRRRRRRRRRRR.........." << std::endl;
	if(rand() %2 == 0)
		std::cout << this->target << " has been robotomized " << std::endl;
	else 
		std::cout << this->target << " has failed to be robotomized " << std::endl;
}