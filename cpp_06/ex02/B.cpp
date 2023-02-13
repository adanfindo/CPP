#include "B.hpp"

B::B(void)
{
	std::cout << "B Default constructor\n";
}

B::B(B const &src)
{
	std::cout << "B Copy constructor\n";
	*this = src;
}

B::~B(void)
{
}

B	&B::operator=(B const & other)
{
	(void)other;
	std::cout << "B Assignement operator\n";
	return *this;
}
