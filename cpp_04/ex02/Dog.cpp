#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Default Dog\n";
}

Dog::Dog(Dog const &src)
{
	std::cout << "Copy Dog\n";
	*this = src;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Destructor Dog\n";
}

Dog	&Dog::operator=(Dog const &other)
{
	Brain *tmp;

	std::cout << "Assignement operator\n";
	this->type = other.getType();
	tmp = other.getBrain();
	this->brain = new Brain();
	for (int i = 0; i < 100; i++)
		this->brain->ideas[i] = other.brain->ideas[i];
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "Wouf\n";
}

Brain	*Dog::getBrain(void) const
{
	return (this->brain);
}
