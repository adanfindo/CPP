#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): type("")
{
	std::cout << "Default WrongAnimal\n";
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "Copy WrongAnimal\n";
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "Destructor WrongAnimal\n";
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &other)
{
	std::cout << "Assignement operator\n";
	this->type = other.getType();
	return *this;
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong Sound\n";
}

const std::string	&WrongAnimal::getType(void) const
{
	return (this->type);
}
