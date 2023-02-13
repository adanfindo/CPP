#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Default Cat\n";
}

Cat::Cat(Cat const &src)
{
	std::cout << "Copy Cat\n";
	*this = src;
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat\n";
}

void	Cat::makeSound(void) const
{
	std::cout << "* MeOw NoIsEs *\n";
}
