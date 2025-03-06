#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("unnamed", 145, 137), target("nobody") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    if(this != &other)
    {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
    if(this->getSigned() == false)
        throw FormNotSignedException();
    if(executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    std::ofstream file((this->target + "_shrubbery").c_str());
    if(!file.is_open())
        std::cerr << "Cannot open the file created" << std::endl;
    
    file << "ASCII trees\n";
    file.close();
}

