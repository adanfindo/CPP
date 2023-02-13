#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name(""), _grade(Bureaucrat::lowestGrade)
{
	std::cout << "Default Bureaucrat\n";
}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name), _grade(grade)
{
	check_grade();
	std::cout << "Standard Bureaucrat\n";
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	std::cout << "Copy Bureaucrat\n";
	*this = src;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destructor Bureaucrat\n";
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const & other)
{
	this->_grade = other._grade;
	std::cout << "Assignement Bureaucrat\n";
	return *this;
}

const std::string	&Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incr_grade(int quantity)
{
	std::cout << "incr_grade of " << quantity << std::endl;
	this->_grade -= quantity;
	check_grade();
}

void	Bureaucrat::decr_grade(int quantity)
{
	std::cout << "decr_grade of " << quantity << std::endl;
	this->_grade += quantity;
	check_grade();
}

void	Bureaucrat::check_grade(void) const
{
	if (this->_grade < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHightExcept();
	else if (this->_grade > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowExcept();
}

std::ostream &	operator<<(std::ostream & ostr, Bureaucrat const & instance)
{
	ostr << instance.getName() << ", Bureaucrat grade " << instance.getGrade();
	return ostr;
}

bool	Bureaucrat::signForm(Form &form) const
{
	if (form.beSigned(*this))
	{
		std::cout << this->_name << " signs form " << form.getName() << std::endl;
		return true;
	}
	else
	{
		std::cout << this->_name << " cannot sign form " << form.getName()
			<< " because their grade is not high enough\n";
		return false;
	}
}

bool	Bureaucrat::executeForm(const Form &form) const
{
	try
	{
		form.checkExecutability(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
		return true;
	}
	catch (Form::CantExecuteForm &e)
	{
		std::cout << e.what() << std::endl;
		return false;
	}
}

