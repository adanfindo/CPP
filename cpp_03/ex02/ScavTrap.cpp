#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_name = "";
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_initialHitPoints = this->_hitPoints;
	std::cout << "ScavTrap Default was built\n";
}

ScavTrap::ScavTrap(const std::string name)
{
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_initialHitPoints = this->_hitPoints;
	std::cout << "ScavTrap " << _name << " was built\n";
}

ScavTrap::ScavTrap(ScavTrap const &src)
{
	std::cout << "ScavTrap was copied\n";
	*this = src;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << _name << " was destroyed\n";
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &other)
{
	std::cout << "Assignement operator\n";
	std::cout << other << std::endl;
	return *this;
}

void	ScavTrap::guardGate(void) const
{
	std::cout << "ScavTrap " << _name << " is keeping SECURE the gate\n";
}

void	ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " need a recharge\n";
		return ;
	}
	this->_energyPoints -= 1;
	std::cout << "ScavTrap " << this->_name << " attack " << target
		<< " causing " << this->_attackDamage << " points of damage!\n";
}