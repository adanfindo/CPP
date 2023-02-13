#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "Default WrongCat\n";
}

WrongCat::WrongCat(WrongCat const &src)
{
	std::cout << "Copy WrongCat\n";
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "Destructor WrongCat\n";
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow\n";
}
