#ifndef ARRAY_TPP
# define ARRAY_TPP

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException()
	: std::out_of_range("Index out of bounds")
{
}

template <typename T>
Array<T>::Array() : _elems(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _elems(NULL), _size(n)
{
	if (n > 0)
		_elems = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : _elems(NULL), _size(other._size)
{
	if (_size > 0)
	{
		_elems = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_elems[i] = other._elems[i];
	}
}

template <typename T>
Array<T>::~Array()
{
	delete[] _elems;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		T* new_elements = NULL;
		if (other._size > 0)
		{
			new_elements = new T[other._size]();
			for (unsigned int i = 0; i < other._size; ++i)
				new_elements[i] = other._elems[i];
		}
		delete[] _elems;
		_elems = new_elements;
		_size = other._size;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elems[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _elems[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif
