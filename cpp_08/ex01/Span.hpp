#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
public:

	Span(void);
	Span(unsigned int size);
	Span(const Span &src);
	~Span(void);
	Span	&operator=(const Span &other);

	void			addNumber(int number);
	int				shortestSpan(void) const;
	int				longestSpan(void) const;

	unsigned int	size(void) const;
	unsigned int	maxSize(void) const;
	unsigned int	spaceLeft(void) const;

	void			randomFill(void);
	void			addByIteratorRange(std::vector<int>::iterator begin,
						std::vector<int>::iterator end);

private:
	unsigned int		_size;
	std::vector<int>	_storage;
};

std::ostream	&operator<<(std::ostream &ostr, Span const &instance);

#endif
