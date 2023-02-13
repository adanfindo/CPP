#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>

class Contact
{
	public:	
		void	set_name(std::string str);
		void	set_last(std::string str);
		void	set_nick(std::string str);
		void	set_number(std::string str);
		void	set_secret(std::string str);

		std::string	get_name(void);
		std::string	get_last(void);
		std::string	get_nick(void);
		std::string	get_number(void);
		std::string	get_secret(void);

		void	print_info(void);

	private:
		std::string	name;
		std::string	last;
		std::string	nick;
		std::string	number;
		std::string	secret;
};

#endif
