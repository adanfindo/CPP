#include "A.hpp"

A::A(void)
{
	std::cout << "A Default constructor\n";
}

A::A(A const &src)
{
	std::cout << "A Copy constructor\n";
	*this = src;
}

A::~A(void)
{
}

A	&A::operator=(A const &other)
{
	(void)other;
	std::cout << "A Assignement operator\n";
	return *this;
}
