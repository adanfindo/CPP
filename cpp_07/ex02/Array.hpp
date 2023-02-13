#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<typename T>
class Array
{

public:
	Array<T>(void): _size(0), _array(NULL)
	{
		std::cout << "Default constructor\n";
	}
	Array<T>(const unsigned int size): _size(size)
	{
		std::cout << "Size constructor\n";
		if (size < 0)
			throw std::overflow_error("Index out of bound");
		this->_array = new T[size];
	}
	Array<T>(const Array<T> &src)
	{
		std::cout << "Copy constructor\n";
		*this = src;
	}
	~Array<T>(void)
	{
		std::cout << "Destructor\n";
		if (this->_size > 0)
			delete [] this->_array;
	}

	Array<T>	&operator=(const Array<T> &other)
	{
		std::cout << "Assignation operator\n";
		if (this == &other)
			return *this;
		if (this->_size > 0)
			delete [] this->_array;
		this->_size = other.size();
		this->_array = new T[this->_size];
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = other[i];
		return *this;
	}
	T	&operator[](const int index) const
	{
		if (index >= this->_size || index < 0)
			throw std::overflow_error("Index out of bound");
		return this->_array[index];
	}

	int	size(void) const
	{
		return this->_size;
	}

private:
	int	_size;
	T	*_array;
};

#endif