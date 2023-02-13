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
	bool	operator>(const Fixed &other) const ;
	bool	operator<(const Fixed &other) const ;
	bool	operator>=(const Fixed &other) const ;
	bool	operator<=(const Fixed &other) const ;
	bool	operator==(const Fixed &other) const ;
	bool	operator!=(const Fixed &other) const ;
	Fixed	operator+(const Fixed &other) const ;
	Fixed	operator-(const Fixed &other) const ;
	Fixed	operator*(const Fixed &other) const ;
	Fixed	operator/(const Fixed &other) const ;
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed		&min(Fixed &first, Fixed &other);
	static const Fixed	&min(const Fixed &first, const Fixed &other);
	static Fixed		&max(Fixed &first, Fixed &other);
	static const Fixed	&max(const Fixed &first, const Fixed &other);

private:
	int					_fixed;
	static const int	_fbits = 8;
};

std::ostream &operator<<(std::ostream &stream, Fixed const &instance);

#endif