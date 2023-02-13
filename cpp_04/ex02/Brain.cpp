#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Default Brain\n";
}

Brain::Brain(Brain const &src)
{
	std::cout << "Copy Brain\n";
	for (int i = 0; i < Brain::numberOfIdeas; i++)
		this->ideas[i] = src.ideas[i];
}

Brain::~Brain(void)
{
	std::cout << "Destructor Brain\n";
}

Brain	&Brain::operator=(Brain const &other)
{
	std::cout << "Assignement operator\n";
	for (int i = 0; i < Brain::numberOfIdeas; i++)
		this->ideas[i] = other.ideas[i];
	return *this;
}
