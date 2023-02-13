#include "C.hpp"

C::C(void)
{
	std::cout << "C Default constructor\n";
}

C::C(C const &src)
{
	std::cout << "C Copy constructor\n";
	*this = src;
}

C::~C(void)
{
}

C	&C::operator=(C const &other)
{
	(void)other;
	std::cout << "C Assignement operator\n";
	return *this;
}