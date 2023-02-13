#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure(void);
	Cure(const Cure &src);
	~Cure(void);
	Cure	&operator=(const Cure &other);
	virtual AMateria	*clone(void) const ;
	virtual void		use(ICharacter& target);
};

#endif