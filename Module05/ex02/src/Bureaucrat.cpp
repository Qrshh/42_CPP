#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("no name"), grade(LOWEST){}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade){
	if(grade < HIGHEST)
		throw GradeTooHighException();
	else if (grade > LOWEST)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade){}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->grade = other.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat(){}

/*Getters */

std::string Bureaucrat::getName() const {return this->name;}
int Bureaucrat::getGrade() const {return this->grade;}


/* Grade functions */

void Bureaucrat::incrementGrade(){
	if(getGrade() - 1 < HIGHEST)
		throw GradeTooHighException();
	this->grade -= 1;
}

void Bureaucrat::decrementGrade(){
	if(getGrade() + 1 > LOWEST)
		throw GradeTooLowException();
	this->grade += 1;
}

void Bureaucrat::signForm(AForm &form)
{
	try{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << "." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " 
		<< form.getName() << " because " << e.what()
		<< std::endl; 
	}
}

/* Exceptions */

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade is too high ! Must be between 1 and 150";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade is too low ! Must be between 1 and 150";
}

std::ostream &operator <<(std::ostream &o, const Bureaucrat &b){
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return o;
}
