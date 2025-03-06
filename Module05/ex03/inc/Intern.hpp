#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"



class Intern{
	private:
		std::string formNames[3];
		AForm* (Intern::*makeForm[3])(const std::string);
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();

		class UnknownFormException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		AForm* makeForm(std::string name, const std::string target);
		AForm* makeShrubberyCreationForm(const std::string &target);
		AForm* makePresidentialPardonForm(const std::string &target);
		AForm* makeRobotomyRequestForm(const std::string &target);
};


#endif