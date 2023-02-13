#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
	Ice(void);
	Ice(const Ice &src);
	~Ice(void);
	Ice		&operator=(const Ice &other);
	virtual AMateria	*clone(void) const ;
	virtual void		use(ICharacter& target);
};

#endif