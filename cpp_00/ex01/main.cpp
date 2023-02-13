#include "PhoneBook.hpp"

void	reset_last(PhoneBook *phonebook)
{
	std::cout << "Field Empty!!\n\n";
	phonebook->phonebook[phonebook->contacts].set_name("");
	phonebook->phonebook[phonebook->contacts].set_last("");
	phonebook->phonebook[phonebook->contacts].set_nick("");
	phonebook->phonebook[phonebook->contacts].set_number("");
}

int	add(PhoneBook *phonebook)
{
	std::string	input;

	std::cout << "Please enter ALL the fields\n";
	std::cout << "First Name: ";
	getline(std::cin, input);
	if (!input.length())
		return(1);
	phonebook->phonebook[phonebook->contacts].set_name(input);
	std::cout << "Last Name: ";
	getline(std::cin, input);
	if (!input.length())
		return (1);
	phonebook->phonebook[phonebook->contacts].set_last(input);
	std::cout << "Nickname: ";
	getline(std::cin, input);
	if (!input.length())
		return (1);
	phonebook->phonebook[phonebook->contacts].set_nick(input);
	std::cout << "Phone Number: ";
	getline(std::cin, input);
	if (!input.length())
		return (1);
	phonebook->phonebook[phonebook->contacts].set_number(input);
	std::cout << "Darkest Secret: ";
	getline(std::cin, input);
	if (!input.length())
		return (1);
	phonebook->phonebook[phonebook->contacts].set_secret(input);
	std::cout << "Contatt Added to PhoneBook\n\n";
	phonebook->contacts++;
	if (phonebook->max_contacts < phonebook->contacts)
		phonebook->max_contacts = phonebook->contacts;
	return (0);
}

std::string	trunc_str(std::string str)
{
	if (str.length() <= 10)
		return (str);
	return (str.substr(0, 9) + ".");
}

void	search(PhoneBook *phonebook)
{
	std::string	input;

	for (int i = 0; i < phonebook->max_contacts; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		std::cout << "|" << std::setw(10) << trunc_str(phonebook->phonebook[i].get_name());
		std::cout << "|" << std::setw(10) << trunc_str(phonebook->phonebook[i].get_last());
		std::cout << "|" << std::setw(10) << trunc_str(phonebook->phonebook[i].get_nick());
		std::cout << "|" << std::endl;
	}
	std::cout << "Select Contact by Index: ";
	getline(std::cin, input);
	if (input.length() == 1 && ('0' < input[0] && input[0] < '9')
		&& (input[0]-49 < phonebook->contacts))
		phonebook->phonebook[input[0] - '0' - 1].print_info();
	else
		std::cout << "Invalid Index!!\n\n";
}

int	main(void)
{
	PhoneBook	phonebook;
	std::string	cmd;
	int			run = 1;

	phonebook.contacts = 0;
	phonebook.max_contacts = 0;
	while (run)
	{
		std::cout << ">> ";
		getline(std::cin, cmd);
		if (cmd == "EXIT")
			run = 0;
		else if (cmd == "ADD")
		{
			if (phonebook.contacts >= 8)
				phonebook.contacts = 0;
			if (add(&phonebook))
				reset_last(&phonebook);
		}
		else if (cmd == "SEARCH")
		{
			if (!phonebook.contacts)
				std::cout << "The PhoneBook is Empty!!\n";
			else
				search(&phonebook);
		}
		else
			std::cout << "Command " << cmd << " not found, try with ADD | SEARCH | EXIT\n";
	}
}
