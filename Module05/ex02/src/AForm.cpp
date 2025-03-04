#include "AForm.hpp"

AForm::AForm() : name("Unnamed"), gradeToSign(LOWEST), gradeToExec(LOWEST),
	isSigned(false)
{
}

AForm::AForm(const std::string &name, const int gradeToSign,
	const int gradeToExec) : name(name), gradeToSign(gradeToSign),
	gradeToExec(gradeToExec), isSigned(false)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name(other.name),
	gradeToSign(other.gradeToSign), gradeToExec(other.gradeToExec),
	isSigned(other.isSigned) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->isSigned = other.getSigned();
	}
	return (*this);
}

AForm::~AForm() {}

std::string AForm::getName() const
{
	return (this->name);
}

int AForm::getGradeToSign() const
{
	return (this->gradeToSign);
}

int AForm::getGradeToExec() const
{
	return (this->gradeToExec);
}

bool AForm::getSigned() const
{
	return (this->isSigned);
}

void AForm::beSigned(const Bureaucrat &bur)
{
	if (bur.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("The bureaucrat's grade is lower than the form's grade");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("The bureaucrat's grade is higher than the form's grade");
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << f.getName() << ", grade for signing: " 
    << f.getGradeToSign() << ". grade for executing: " 
    << f.getGradeToExec() << ", is signed: " 
    << (f.getSigned() ? "true" : "false") << "." 
    << std::endl;
	return (o);
}
