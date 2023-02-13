#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat(void);
	Cat(const Cat &src);
	~Cat(void);
	Cat				&operator=(Cat const &other);
	virtual void	makeSound(void) const;
	Brain	*getBrain(void) const;
private:
	Brain	*brain;
};

#endif
