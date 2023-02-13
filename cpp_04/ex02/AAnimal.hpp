#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
public:
	virtual ~AAnimal(void);
	AAnimal				&operator=(const AAnimal &other);
	virtual void		makeSound(void) const = 0;
	const std::string	&getType(void) const;
protected:
	std::string type;
};

#endif
