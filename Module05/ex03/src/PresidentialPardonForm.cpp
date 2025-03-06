#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("unnamed", 25, 5), target("nobody") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const 
{
	if(this->getSigned() == false)
		throw FormNotSignedException();
	if(executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException();
	std::cout << this->target << " has been pardoned by Zaphod Beeblerox" << std::endl; 
}