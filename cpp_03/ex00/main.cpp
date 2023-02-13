#include "ClapTrap.hpp"

int	main() {
	ClapTrap clap("clap");
	clap.attack("Handsome Jack");
	clap.takeDamage(6);
	clap.beRepaired(4);
	clap.takeDamage(3);
	clap.beRepaired(8);
	clap.takeDamage(17);
}