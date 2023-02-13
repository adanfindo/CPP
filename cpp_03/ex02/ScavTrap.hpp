#ifndef SCRAVTRAP_HPP
# define SCRAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap(const std::string name);
	ScavTrap(const ScavTrap &src);
	ScavTrap(void);
	~ScavTrap(void);
	ScavTrap	&operator=(const ScavTrap &other);
	void		attack(const std::string &target);
	void		guardGate(void) const;
};

#endif