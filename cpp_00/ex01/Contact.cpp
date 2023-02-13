#include "Contact.hpp"

void	Contact::set_name(std::string str)
{

	name = str;
}
void	Contact::set_last(std::string str)
{
	last = str;
}
void	Contact::set_nick(std::string str)
{
	nick = str;
}
void	Contact::set_number(std::string str)
{
	number = str;
}
void	Contact::set_secret(std::string str)
{
	secret = str;
}

std::string	Contact::get_name(void)
{
	return (name);
}
std::string	Contact::get_last(void)
{
	return (last);
}
std::string	Contact::get_nick(void)
{
	return (nick);
}
std::string	Contact::get_number(void)
{
	return (number);
}
std::string	Contact::get_secret(void)
{
	return (secret);
}

void	Contact::print_info(void)
{
	std::cout << "First Name:	" << name << std::endl;
	std::cout << "Last Name:	" << last << std::endl;
	std::cout << "Nickname:		" << nick << std::endl;
	std::cout << "Phone Number:	" << number << std::endl;
	std::cout << "Darkest Secret:	" << secret << std::endl;
}
