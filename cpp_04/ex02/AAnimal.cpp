#include "AAnimal.hpp"

AAnimal::~AAnimal(void)
{
	std::cout << "Destructor AAnimal\n";
}

AAnimal	&AAnimal::operator=(AAnimal const &other)
{
	std::cout << "Assignement operator\n";
	this->type = other.getType();
	return *this;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "* AANIMAL SOUND *\n";
}

const std::string	&AAnimal::getType(void) const
{
	return (this->type);
}