#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


class Bureaucrat;

class Form{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExec;
		bool signed;

	public:
		Form();
		Form(const std::string &name,
				const int gradeToSign,
				const int gradeToExec);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();

		std::string getName()const;
		int getGradeToSign()const;
		int getGradeToExec() const;
		bool getSigned() const;

		class GradeTooHighException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public: 
				virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &bur);
};



#endif