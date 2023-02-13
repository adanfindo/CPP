#include "ScavTrap.hpp"

int	main() {
	ScavTrap scav("scav");
	scav.attack("Handsome Jack");
	scav.takeDamage(6);
	scav.beRepaired(4);
	scav.takeDamage(3);
	scav.guardGate();
	scav.beRepaired(8);
	scav.takeDamage(17);
	std::cout << "----------------------------------------\n";
	ClapTrap clap("clap");
	clap.attack("Handsome Jack");
	clap.takeDamage(6);
	clap.beRepaired(4);
	clap.takeDamage(3);
	clap.beRepaired(8);
	clap.takeDamage(17);
}