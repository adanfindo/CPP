#include "Form.hpp"

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute):
	_name(name), _isSigned(false), _gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute)
{
	this->check_grades();
	std::cout << "Standard Form\n";
}

Form::Form(void): _name(""), _isSigned(false),
	_gradeToSign(Form::lowestGrade), _gradeToExecute(Form::lowestGrade)
{
	std::cout << "Default Form\n";
}

Form::Form(Form const & src): _name(src.getName()), _isSigned(src.isSigned()),
	_gradeToSign(src.getSignGrade()), _gradeToExecute(src.getExecuteGrade())
{
	std::cout << "Copy Form\n";
	*this = src;
}

Form::~Form(void)
{
	std::cout << "Destructor Form\n";
}

Form	&Form::operator=(Form const &other)
{
	this->_isSigned = other._isSigned;
	std::cout << "Assignement Form\n";
	return *this;
}

const std::string	&Form::getName(void) const
{
	return this->_name;
}

int	Form::getSignGrade(void) const
{
	return this->_gradeToSign;
}

int	Form::getExecuteGrade(void) const
{
	return this->_gradeToExecute;
}

bool	Form::isSigned(void) const
{
	return this->_isSigned;
}

void	Form::checkExecutability(const Bureaucrat &bureaucrat) const
{
	if (this->_isSigned == false
			|| bureaucrat.getGrade() > this->_gradeToExecute)
		throw Form::CantExecuteForm();
}

void	Form::check_grades(void) const
{
	if (this->_gradeToExecute < Form::highestGrade
			|| this->_gradeToSign < Form::highestGrade)
		throw Form::GradeTooHightExcept();
	if (this->_gradeToExecute > Form::lowestGrade
			|| this->_gradeToSign > Form::lowestGrade)
		throw Form::GradeTooLowExcept();
}

bool	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() < this->_gradeToSign)
	{
		this->_isSigned = true;
		return true;
	}
	else
	{
		this->_isSigned = false;
		return false;
	}
}

std::ostream	&operator<<(std::ostream & ostr, Form const & instance)
{
	ostr << instance.getName() << " signed by "
		<< instance.getSignGrade() << ", graded by "
		<< instance.getExecuteGrade() << ", it is "
		<< ((instance.isSigned()) ? "" : "not ") << "signed";
	return ostr;
}
