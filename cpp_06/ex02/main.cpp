#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	int	selected = rand() % 3;

	if (selected == 0)
		return new A();
	else if (selected == 1)
		return new B();
	else if (selected == 2)
		return new C();
	else
		throw new std::exception();
}

void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C\n";
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}

void	identify(Base *p)
{
	A *a;
	if ((a = dynamic_cast<A *>(p)))
		std::cout << "A\n";
	B *b;
	if ((b = dynamic_cast<B *>(p)))
		std::cout << "B\n";
	C *c;
	if ((c = dynamic_cast<C *>(p)))
		std::cout << "C\n";
}

int		main(void)
{
	Base	*base;

	std::cout << "Identifying with pointers\n";

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	base = generate();
	identify(base);
	delete base;

	std::cout << "\n\n";

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;

	base = generate();
	identify(*base);
	delete base;
}