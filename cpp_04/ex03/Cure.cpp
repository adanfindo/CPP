#include "Cure.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Default Cure\n";
}

Cure::Cure(Cure const & src): AMateria("cure")
{
	std::cout << "Copy Cure\n";
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << "Destructor Cure\n";
}

Cure	&Cure::operator=(const Cure &other)
{
	this->_type = other._type;
	std::cout << "Assignation Cure\n";
	return *this;
}

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "\'s wounds *\n";
}
