#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "Standard PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(void):
	Form("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << "Default PresidentialPardonForm\n";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src):
	Form("PresidentialPardonForm", 25, 5), _target(src.getTarget())
{
	std::cout << "Copy PresidentialPardonForm\n";
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destructor PresidentialPardonForm\n";
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	other.getTarget();
	std::cout << "Assignement PresidentialPardonForm\n";
	return *this;
}

const std::string	&PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::execute( const Bureaucrat &executor) const
{
	this->checkExecutability(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
