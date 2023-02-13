#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "Standard RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(void):
	Form("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << "Default RobotomyRequestForm\n";
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src):
	Form("RobotomyRequestForm", 72, 45), _target(src.getTarget())
{
	std::cout << "Copy RobotomyRequestForm\n";
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destructor RobotomyRequestForm\n";
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	other.getTarget();
	std::cout << "Assignement RobotomyRequestForm\n";
	return *this;
}

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << " * DRILLING NOISES * \n";
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized\n";
	else
		std::cout << this->_target << " robotomization has failed\n";
}
