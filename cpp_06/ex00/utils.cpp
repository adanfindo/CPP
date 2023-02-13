#include <iostream>
#include <limits>
#include <cmath>

bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void	print_help(void)
{
	std::cout << "./convert {char, int, float or double}\n" ;
}

bool	canConvertToInt(double number)
{
	return (number <= std::numeric_limits<int>::max()
			&& number >= std::numeric_limits<int>::min()
			&& number != std::numeric_limits<double>::infinity()
			&& number != -std::numeric_limits<double>::infinity()
			&& number != std::numeric_limits<double>::quiet_NaN());
}

bool	canConvertToFloat(double number)
{
	return ((number <= std::numeric_limits<float>::max()
			&& number >= -std::numeric_limits<float>::max())
			|| number == std::numeric_limits<double>::infinity()
			|| number == -std::numeric_limits<double>::infinity()
			|| std::isnan(number));
}

const char	*printDotZero(double number)
{
	if (number - static_cast<int>(number) == 0.0)
		return (".0");
	return ("");
}