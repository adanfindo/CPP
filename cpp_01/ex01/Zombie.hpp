#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
	public:
		~Zombie(void);
		void	announce(void);
		void	set_name(std::string _name);
	private:
		std::string	name;
};

Zombie	*zombieHorde(int N, std::string name);

#endif