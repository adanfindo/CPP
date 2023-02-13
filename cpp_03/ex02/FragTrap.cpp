#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_initialHitPoints = this->_hitPoints;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << _name << " was built\n";
}

FragTrap::FragTrap(void)
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_initialHitPoints = this->_hitPoints;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap Default was built\n";
}

FragTrap::FragTrap(FragTrap const & src)
{
	std::cout << "FragTrap was copied\n";
	*this = src;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap " << _name << " was destroyed\n";
}

FragTrap	&FragTrap::operator=(FragTrap const &other)
{
	std::cout << "Assignement operator\n";
	std::cout << other << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void) const
{
	std::cout << "Hey guys! Give me a high five!!! (plz)\n";
}
