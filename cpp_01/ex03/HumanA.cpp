#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon& _weapon) : weapon(_weapon)
{
	this->name = _name;
	//this->weapon = _weapon;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}