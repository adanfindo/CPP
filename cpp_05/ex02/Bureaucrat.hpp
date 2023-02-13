#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{

public:

	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &src);
	~Bureaucrat(void);

	Bureaucrat	&operator=(const Bureaucrat &other);

	const std::string	&getName(void) const;
	int					getGrade(void) const;
	void	incr_grade(int quantity);
	void	decr_grade(int quantity);
	bool	executeForm(const Form &form) const;
	bool	signForm(Form &form) const;

private:

	const std::string	_name;
	int					_grade;

	static const int	lowestGrade = 150;
	static const int	highestGrade = 1;

	void	check_grade(void) const;

public:

	class GradeTooHightExcept : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The grade is too high");
		}
	};

	class GradeTooLowExcept : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("The grade is too low");
		}
	};

};

std::ostream	&operator<<(std::ostream &ostr, const Bureaucrat &instance);

#endif
