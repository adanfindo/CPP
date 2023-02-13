#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal &src);
	~WrongAnimal(void);
	WrongAnimal			&operator=(const WrongAnimal &other);
	void				makeSound(void) const;
	const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif
