#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	formNames[0] = "shrubbery creation";
	formNames[1] = "presidential pardon";
	formNames[2] = "robotomy request";
	formMakers[0] = &Intern::makeShrubberyCreationForm;
	formMakers[1] = &Intern::makePresidentialPardonForm;
	formMakers[2] = &Intern::makeRobotomyRequestForm;
}

Intern::~Intern() {}

Intern::Intern(const Intern &other){
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		this->formNames[0] = other.formNames[0];
		formMakers[0] = other.formMakers[0];
	}
	return *this;
}

const char* Intern::UnknownFormException::what() const throw(){
	return "Form is unknown\n";
}

AForm* Intern::makeShrubberyCreationForm(const std::string &target){
	return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string &target){
	return new RobotomyRequestForm(target);
}

AForm* Intern::makePresidentialPardonForm(const std::string &target){
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string name, const std::string target){
	int i = -1;
	while(++i < 3)
	{
		if(formNames[i] == name){
			std::cout << "Intern creates " << name << std::endl;
			return ((this->*formMakers[i])(target));
		}
	}
	throw UnknownFormException();
	return NULL;
}