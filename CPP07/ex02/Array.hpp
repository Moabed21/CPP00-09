#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>
#include <stdlib.h>

template <typename T>
class Array
{
private:
	T*				_elems;
	unsigned int	_size;

public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	~Array();

	Array& operator=(const Array& other);

	// Subscript operators
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	// Member functions
	unsigned int size() const;

	// Exception class
	class OutOfBoundsException : public std::out_of_range
	{
	public:
		OutOfBoundsException();
	};
};

# include "Array.tpp"

#endif
