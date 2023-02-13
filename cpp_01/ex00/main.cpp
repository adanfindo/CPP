#include "Zombie.hpp"

int		main(void)
{
	Zombie test("Mario");
	std::cout << "Test 1\n";
	test.announce();

	std::cout << "\nTest 2\n";
	Zombie *test_2 = newZombie("Giovanni");
	test_2->announce();

	std::cout << "\nTest 3\n";
	randomChump("Federico");

	std::cout << std::endl;
	delete test_2;
}
