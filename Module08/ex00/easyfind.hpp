#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <algorithm>

class NotFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Not found");
		}
};

template <typename T>
typename T::iterator easyfind(T& container, int i)
{
	typename T::iterator iter = std::find(container.begin(), container.end(), i);
	
	if (iter == container.end())
		throw NotFound();
	return (iter);
}

#endif