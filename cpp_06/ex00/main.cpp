#include "ScalarType.hpp"
#include "utils.hpp"

int	main(int argc, char **argv)
{
	ScalarType scalar;

	try
	{
		if (argc == 1)
			throw (ScalarType::EmptyInput());
		for (int i = 1; i < argc; i++)
		{
			scalar.analyseNewInput(argv[i]);
			scalar.printTypes();
			if (i + 1 < argc)
				std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		print_help();
	}
}