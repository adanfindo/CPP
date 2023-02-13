#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Default Dog\n";
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy Dog\n";
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog\n";
}


void	Dog::makeSound(void) const
{
	std::cout << "Wouf\n";
}
