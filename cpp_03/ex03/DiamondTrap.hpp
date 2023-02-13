#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap
{
public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &src);
	DiamondTrap(void);
	~DiamondTrap(void);
	DiamondTrap	&operator=(DiamondTrap const &other);
	void		attack(const std::string &target);
	void		whoAmI(void) const;
private:
	std::string	_name;
};

#endif