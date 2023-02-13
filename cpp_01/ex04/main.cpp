#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <ios>
#include <exception>

int	main(int argc, char **argv)
{
	if (argc != 4 || !strlen(argv[1]) || !strlen(argv[2]) || !strlen(argv[3]))
	{
		std::cout << "Error: Invalid arguments\n";
		return 1;
	}
	std::string 	input;
	std::size_t		re;
	std::size_t		i = 0;
	std::ofstream	sed;
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	int 			len = strlen(argv[2]);

	std::ifstream	file;
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		file.open(argv[1], std::ifstream::in);
	} catch (const std::ifstream::failure) {
		std::cout << "Error: file does not exist" << std::endl;
		return 1;
	}

	sed.open(strcat(argv[1], ".replace"), std::ofstream::trunc);
	std::getline(file, input, '\0');
	re = input.find(s1);
	while (re != std::string::npos)
	{
		while (i != re)
			sed << input[i++];
		sed << s2;
		i += len;
		re = input.find(s1, i);
	}
	while (i != input.size())
		sed << input[i++];
	sed.close();
	file.close();
}
