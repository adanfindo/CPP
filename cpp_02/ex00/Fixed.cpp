#include "Fixed.hpp"

Fixed::Fixed(void): _fixed(0)
{
	std::cout << "Default constructor called\n";
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
	this->_fixed = other.getRawBits();
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