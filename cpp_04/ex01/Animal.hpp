#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(const Animal &src);
	virtual ~Animal(void);
	Animal				&operator=(const Animal &other);
	virtual void		makeSound(void) const;
	const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif
