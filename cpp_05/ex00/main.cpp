#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	b1 = Bureaucrat("b1", 1);
		std::cout << b1 << std::endl;
		b1.decr_grade(1);
		std::cout << b1 << std::endl;
		b1.incr_grade(1);
		std::cout << b1 << std::endl;
		b1.incr_grade(1);
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b2 = Bureaucrat("b2", 150);
		std::cout << b2 << std::endl;
		b2.incr_grade(1);
		std::cout << b2 << std::endl;
		b2.decr_grade(1);
		std::cout << b2 << std::endl;
		b2.decr_grade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b3 = Bureaucrat("b3", 0);
		std::cout << b3 << std::endl;
		b3.decr_grade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat		b4 = Bureaucrat("b4", 151);
		std::cout << b4 << std::endl;
		b4.incr_grade(1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
