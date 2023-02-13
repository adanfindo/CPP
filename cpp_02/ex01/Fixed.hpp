#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(int fixed);
	Fixed(float fixed);
	Fixed(const Fixed &src);
	~Fixed(void);
	Fixed	&operator=(const Fixed &other);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
private:
	int					_fixed;
	static const int	_fbits = 8;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &instance);

#endif