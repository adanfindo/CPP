#include "ClapTrap.hpp"

ClapTrap::ClapTrap(ClapTrap const &src)
{
	std::cout << "ClapTrap was copied\n";
	*this = src;
}

ClapTrap::ClapTrap(void): _name(""), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	this->_initialHitPoints = this->_hitPoints;
	std::cout << "ClapTrap Default was built\n";
}

ClapTrap::ClapTrap(const std::string name): _name(name), _hitPoints(10),
	_energyPoints(10), _attackDamage(0)
{
	this->_initialHitPoints = this->_hitPoints;
	std::cout << "ClapTrap " << _name << " was built\n";
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap " << _name << " was destroyed\n";
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &other)
{
	std::cout << "Assignement operator\n";
	std::cout << other << std::endl;
	return *this;
}

const std::string	&ClapTrap::getName(void) const
{
	return this->_name;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " need a recharge\n";
		return ;
	}
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attack " << target
		<< " causing " << this->_attackDamage << " points of damage!\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " took damage\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " need a recharge\n";
		return ;
	}
	this->_energyPoints--;
	this->_hitPoints += amount;
	if (this->_hitPoints > this->_initialHitPoints)
	{
		this->_hitPoints = this->_initialHitPoints;
		std::cout << "ClapTrap " << _name << " max healed\n";
	}
	std::cout << "ClapTrap " << _name << " repaired itself\n";
}

std::ostream	&operator<<(std::ostream & ostr, ClapTrap const & instance)
{
	ostr << "ClapTrap " << instance.getName();
	return ostr;
}
