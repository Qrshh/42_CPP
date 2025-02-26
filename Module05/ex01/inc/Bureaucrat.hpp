#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#define HIGHEST 1
#define LOWEST 150

class Bureaucrat{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat (const Bureaucrat &other);
		virtual ~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &other);

		std::string getName()const;
		int	getGrade()const;

		void incrementGrade();
		void decrementGrade();


		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw();
		};

	};
	std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);



#endif