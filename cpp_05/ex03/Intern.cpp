#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Default Intern\n";
}

Intern::Intern(Intern const &src)
{
	std::cout << "Copy Intern\n";
	*this = src;
}

Intern::~Intern(void)
{
	std::cout << "Destructor Intern\n";
}

Intern	&Intern::operator=(Intern const &other)
{
	(void)other;
	std::cout << "Assignement Intern\n";
	return *this;
}

Form	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	t_forms forms[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL }
	};
	Form	*result = NULL;

	for (int i = 0; forms[i].type != NULL; i++)
	{
		if (forms[i].name == form)
			result = forms[i].type;
		else
			delete forms[i].type;
	}
	if (result == NULL)
		std::cout << "Intern did not find the form " << form << std::endl;
	else
		std::cout << "Intern creates " << form << std::endl;
	return result;
}

std::ostream &	operator<<( std::ostream & ostr, Intern const & instance)
{
	(void)instance;
	ostr << "Intern\n";
	return ostr;
}
