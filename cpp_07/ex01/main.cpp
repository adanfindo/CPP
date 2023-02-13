#include <iostream>
#include <cstdlib>
#include "iter.hpp"

template<typename T>
void	display(T &whatever)
{
	std::cout << whatever << std::endl;
}

void	setRandomValue(int &number)
{
	number = std::rand() % 100;
}

int	main( void )
{
	std::string	strTable[3];
	int			*intTable = new int[5];

	strTable[0] = "first test";
	strTable[1] = "Is it working?";
	strTable[2] = "Very good!";
	::iter(strTable, 3, &display);
	for (int i = 0; i < 5; i ++)
		setRandomValue(intTable[i]);
	::iter(intTable, 5, &display);
}