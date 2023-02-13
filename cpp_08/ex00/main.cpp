#include <iostream>
#include <vector>
#include "easyfind.hpp"

int	main(void)
{
	std::vector<int>			vect;
	std::vector<int>::iterator	it;

	for (int i = 1; i < 59; i += 2)
		vect.push_back(i);
	try
	{
		it = easyfind(vect, 43);
		std::cout << "iterator: " << *it << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		it = easyfind(vect, 42);
		std::cout << "iterator: " << *it << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
