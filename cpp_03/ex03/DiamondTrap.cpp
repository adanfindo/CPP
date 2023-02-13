#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name)
{
	ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << _name << " was built\n";
}

DiamondTrap::DiamondTrap(void)
{
	ClapTrap::_name = "Default_clap_name";
	this->_name = "Default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default was built\n";
}

DiamondTrap::DiamondTrap(DiamondTrap const &src)
{
	std::cout << "DiamondTrap was copied\n";
	*this = src;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap " << _name << " was destroyed\n";
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &other)
{
	std::cout << "Assignement operator\n";
	std::cout << other << std::endl;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << "Who am I, " << this->_name << " or " << ClapTrap::_name << " ?\n";
}
