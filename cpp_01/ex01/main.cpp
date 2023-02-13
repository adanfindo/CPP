#include "Zombie.hpp"

int		main(void)
{
	int		n;
	std::cout << "Enter number of Zombies: ";
	std::cin >> n;

	Zombie	*horde = zombieHorde(n, "Test");

	for (int i = 0; i < n; i++)
		horde[i].announce();

	std::cout << std::endl;
	delete [] horde;
}
