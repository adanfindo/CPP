#include "Bureaucrat.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern		slaver;
	Bureaucrat	b1("b1", 3);
	Form		*form;

	form = slaver.makeForm("error test", "Name 0");
	if (form)
		delete form;
	form = slaver.makeForm("presidential pardon", "Name 1");
	if (form)
		delete form;
	form = slaver.makeForm("shrubbery creation", "Name 2");
	if (form)
		delete form;
	form = slaver.makeForm("robotomy request", "Name 3");
	form->beSigned(b1);
	form->execute(b1);
	if (form)
		delete form;
}
