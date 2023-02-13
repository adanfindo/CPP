#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{

public:

	Intern(void);
	Intern(const Intern &src);
	~Intern(void);

	Intern	&operator=(const Intern &other);

	Form	*makeForm(const std::string &form, const std::string &target) const;

private:

	typedef struct	s_forms
	{
		std::string	name;
		Form		*type;
	}	t_forms;
};

std::ostream	&operator<<( std::ostream &ostr, const Intern &instance );

#endif
