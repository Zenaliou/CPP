#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstdlib>
#include <iostream>

template <typename T>
class Array
{
	private:
	    T*				_array;
	    unsigned int	_size;

	public:
	    Array() : _array(NULL), _size(0) {}

	    Array(unsigned int n) : _array(new T[n]()), _size(n) {}

		Array(const Array& other) : _array(NULL), _size(0)
	    {
	        *this = other;
	    }

	    Array& operator=(const Array& other)
	    {
	        if (this != &other)
	        {
	            if (_array)
	                delete[] _array;
	            _size = other._size;
	            _array = new T[_size];
	            for (unsigned int i = 0; i < _size; ++i)
	                _array[i] = other._array[i];
	        }
	        return *this;
	    }

	    ~Array()
	    {
	        if (_array)
	            delete[] _array;
	    }

	    T& operator[](unsigned int index)
	    {
	        if (index >= _size)
	            throw OutOfBoundsException();
	        return _array[index];
	    }

	    const T& operator[](unsigned int index) const
	    {
	        if (index >= _size)
	            throw OutOfBoundsException();
	        return _array[index];
	    }

	    unsigned int size() const
	    {
	        return _size;
	    }

	    class OutOfBoundsException : public std::exception
	    {
	    public:
	        virtual const char* what() const throw()
	        {
	            return "Index out of bounds";
	        }
	    };
};

#endif