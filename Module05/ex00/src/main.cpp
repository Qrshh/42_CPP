#include "Bureaucrat.hpp"

int main()
{
	try{
		Bureaucrat obj("oui", 150);
		std::cout << obj << std::endl;

		try{
			obj.decrementGrade();
			std::cout << obj << std::endl;
		} catch(Bureaucrat::GradeTooLowException &e){
			std::cout <<e.what() << std::endl;
		}

		std::cout << std::endl;

		Bureaucrat Bur("JonnDoe", 1);
		std::cout << Bur << std::endl;

		try{
			Bur.incrementGrade();
			std::cout << Bur << std::endl;
		} catch (Bureaucrat::GradeTooHighException &e){
			std::cout << e.what() << std::endl;
		}

		std::cout << std::endl;


		Bureaucrat Bur2("JaneDoe", 10);
		std::cout << Bur2 << std::endl;

		try{
			Bur2.decrementGrade();
			std::cout << Bur2 << std::endl;
		} catch (std::exception &e){
			std::cout << e.what() << std::endl;
		}
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	return(0);
}