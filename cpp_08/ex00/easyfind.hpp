#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::iterator	easyfind(T &container, int to_find)
{
	typename T::iterator found = std::find(container.begin(), container.end(), to_find);
	return ((found == container.end()) ? throw(std::out_of_range("Not found")) : found);
}

#endif
