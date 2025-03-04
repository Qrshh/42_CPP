#include "Form.hpp"

Form::Form() : name("Unnamed"), gradeToSign(LOWEST), gradeToExec(LOWEST),
	isSigned(false)
{
}

Form::Form(const std::string &name, const int gradeToSign,
	const int gradeToExec) : name(name), gradeToSign(gradeToSign),
	gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name(other.name),
	gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec),
	isSigned(other.isSigned) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->isSigned = other.getSigned();
	}
	return (*this);
}

Form::~Form() {}

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool Form::getSigned() const
{
	return (this->isSigned);
}

void Form::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat's grade is lower than the form's grade");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat's grade is higher than the form's grade");
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << f.getName() << ", grade for signing: " 
    << f.getGradeToSign() << ". grade for executing: " 
    << f.getGradeToExec() << ", is signed: " 
    << (f.getSigned() ? "true" : "false") << "." 
    << std::endl;
	return (o);
}
