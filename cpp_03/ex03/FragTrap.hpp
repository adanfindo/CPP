#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap(const std::string &name);
	FragTrap(const FragTrap &src);
	FragTrap(void);
	~FragTrap(void);
	FragTrap	&operator=(FragTrap const &other);
	void		highFivesGuys(void) const ;
};

#endif