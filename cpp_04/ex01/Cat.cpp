#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Default Cat\n";
}

Cat::Cat(Cat const &src)
{
	std::cout << "Copy Cat\n";
	*this = src;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << "Destructor Cat\n";
}

Cat	&Cat::operator=(Cat const &other)
{
	std::cout << "Assignement operator\n";
	this->type = other.getType();
	this->brain = other.getBrain();
	return *this;
}

void	Cat::makeSound(void) const
{
	std::cout << "* MeOw NoIsEs *\n";
}

Brain	*Cat::getBrain(void) const
{
	return (this->brain);
}
