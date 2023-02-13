#include "Fixed.hpp"

int		power(int val, int exp)
{
	int		i = -1;
	int		res = 1;
	while (++i < exp)
		res *= val;
	return (res);
}

Fixed::Fixed(void): _fixed(0)
{
}

Fixed::Fixed(int fixed)
{
	this->_fixed = fixed << this->_fbits;
}

Fixed::Fixed(float fixed)
{
	int pow = power(2, this->_fbits);

	this->_fixed = roundf(fixed * pow);
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed &Fixed::operator=(Fixed const &other)
{
	this->_fixed = other._fixed;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	return (this->_fixed);
}

void	Fixed::setRawBits(const int raw)
{
	this->_fixed = raw;
}

int	Fixed::toInt( void ) const
{
	return (this->_fixed >> this->_fbits);
}

float	Fixed::toFloat( void ) const
{
	int		pow = power(2, this->_fbits);
	float	result = (float)this->_fixed / pow;

	return (result);
}

std::ostream &operator<<(std::ostream &stream, Fixed const &instance)
{
	stream << instance.toFloat();
	return (stream);
}



bool	Fixed::operator>(const Fixed &other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool	Fixed::operator<(const Fixed &other) const
{
	return (other > *this);
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return (!(*this < other));
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return (!(*this > other));
}

bool	Fixed::operator==(const Fixed &other) const
{
	return (other.getRawBits() == this->getRawBits());
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return (!(other == *this));
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	result(this->toFloat() * other.toFloat());

	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	result(this->toFloat() / other.toFloat());

	return (result);
}

Fixed	&Fixed::operator++(void)
{
	this->_fixed++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	old(*this);

	++(*this);
	return (old);
}

Fixed	&Fixed::operator--(void)
{
	this->_fixed--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	old(*this);

	--(*this);
	return (old);
}



Fixed		&Fixed::min(Fixed &first, Fixed &other)
{
	if (first < other)
		return (first);
	return (other);
}

const Fixed		&Fixed::min(const Fixed &first, const Fixed &other)
{
	if (first < other)
		return (first);
	return (other);
}

Fixed		&Fixed::max(Fixed &first, Fixed &other)
{
	if (first > other)
		return (first);
	return (other);
}

const Fixed		&Fixed::max(const Fixed &first, const Fixed &other)
{
	if (first > other)
		return (first);
	return (other);
}