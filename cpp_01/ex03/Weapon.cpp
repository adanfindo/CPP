#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
	this->type = _type;
}

const std::string& Weapon::getType(void)
{
	std::string& ref = type;
	return (ref);
}

void	Weapon::setType(std::string _type)
{
	this->type = _type;
}