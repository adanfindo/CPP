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
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(int fixed)
{
	std::cout << "Int constructor called\n";
	this->_fixed = fixed << this->_fbits;
}

Fixed::Fixed(float fixed)
{
	int pow = power(2, this->_fbits);

	std::cout << "Float constructor called\n";
	this->_fixed = roundf(fixed * pow);
}

Fixed::Fixed(Fixed const & src)
{
	std::cout << "Copy constructor called\n";
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
}

Fixed &Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called\n";
	this->_fixed = other._fixed;
	return *this;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_fixed);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called\n";
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