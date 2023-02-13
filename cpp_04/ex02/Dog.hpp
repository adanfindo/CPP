#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
{
public:
	Dog(void);
	Dog(const Dog &src);
	~Dog(void);
	Dog				&operator=(Dog const &other);
	virtual void	makeSound(void) const;
	virtual Brain	*getBrain(void) const;
private:
	Brain	*brain;
};

#endif