#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
	Array();
	Array(unsigned int);
	Array(const Array& other);
	Array& operator=(const Array& other);
	~Array();

	unsigned int size() const;
};
#endif