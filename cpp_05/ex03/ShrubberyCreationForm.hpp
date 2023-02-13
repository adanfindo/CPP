#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{

public:

	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);

	const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;

private:

	const std::string		_target;

};

#endif
