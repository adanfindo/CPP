#include "Ice.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Default Ice\n";
}

Ice::Ice(Ice const & src): AMateria("ice")
{
	std::cout << "Copy Ice\n";
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "Destructor Ice\n";
}

Ice	&Ice::operator=(const Ice &other)
{
	this->_type = other._type;
	std::cout << "Assignation Ice\n";
	return *this;
}

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}