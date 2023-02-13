#include "Zombie.hpp"

Zombie::~Zombie(void)
{
	std::cout << name << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::set_name(std::string _name)
{
	name = _name;
}