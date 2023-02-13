#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Form			*form = NULL;
	Bureaucrat		b1("b1", 1);
	Bureaucrat		b2("b2", 40);
	Bureaucrat		b3("b3", 150);

	try
	{
		form = new PresidentialPardonForm("f1");
		form->execute(b1);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new PresidentialPardonForm("f2");
		form->beSigned(b1);
		form->execute(b1);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new RobotomyRequestForm("f3");
		form->beSigned(b1);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		form->execute(b2);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


	try
	{
		form = new ShrubberyCreationForm("f4");
		form->beSigned(b1);
		form->execute(b2);
		form->execute(b3);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
