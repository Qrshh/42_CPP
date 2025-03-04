#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


#define LOWEST 150
#define HIGHEST 1

class Bureaucrat;

class AForm{
	private:
		const std::string name;
		const int gradeToSign;
		const int gradeToExec;
		bool isSigned;

	public:
		AForm();
		AForm(const std::string &name,
				const int gradeToSign,
				const int gradeToExec);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();

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

		class FormNotSignedException : public std::exception{
			public:
				virtual const char* what() const throw();
		};

		void beSigned(const Bureaucrat &bur);
		virtual void execute(const Bureaucrat &exec) const = 0;
};
		std::ostream &operator<<(std::ostream &o, const AForm &f);



#endif