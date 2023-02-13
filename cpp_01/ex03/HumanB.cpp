#include "HumanB.hpp"

HumanB::HumanB(std::string _name)
{
	this->name = _name;
}

void	HumanB::setWeapon(Weapon& _weapon)
{
	this->weapon = &_weapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}