# include "AForm.hpp"
# include "Intern.hpp"
# include "Bureaucrat.hpp"

int	main(void)
{
	{
		try {
			Intern	someRandomIntern;
			Bureaucrat bob("bob", 26);
			AForm* 	rrf;
			rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
			std::cout << *rrf << std::endl;

			bob.signForm(*rrf);

			std::cout << std::endl;

			bob.executeForm(*rrf);

			std::cout << std::endl;

			std::cout << *rrf << std::endl;
			delete rrf;

			rrf = someRandomIntern.makeForm("robotomy request", "28B");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;
			delete rrf;

			rrf = someRandomIntern.makeForm("presidential pardon", "28A");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;
			delete rrf;

			rrf = someRandomIntern.makeForm("oui oui baguette", "28A");
			std::cout << *rrf << std::endl;
			std::cout << std::endl;
			delete rrf;

		} catch (Intern::UnknownFormException & e) {
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}