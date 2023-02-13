#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include "Form.hpp"
# include "Bureaucrat.hpp"

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	~RobotomyRequestForm(void);

	RobotomyRequestForm	&operator=(const RobotomyRequestForm &other);

	const std::string	&getTarget(void) const;
	virtual void		execute(const Bureaucrat &executor) const;

private:

	const std::string		_target;

};

#endif
