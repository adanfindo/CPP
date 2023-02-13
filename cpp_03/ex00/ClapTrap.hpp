#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:
	ClapTrap(const std::string name);
	ClapTrap(const ClapTrap &src);
	ClapTrap(void);
	~ClapTrap(void);
	ClapTrap	&operator=(const ClapTrap &other);
	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	const std::string	&getName(void) const;
protected:
	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_initialHitPoints;
	int			_attackDamage;
};

std::ostream	&operator<<(std::ostream & ostr, ClapTrap const & instance);

#endif