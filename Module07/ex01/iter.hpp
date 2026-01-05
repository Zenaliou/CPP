#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <iterator>

template <typename T, typename F>
void iter(T *array, int len, F func)
{
	for (int i = 0; i < len; ++i)
		func(array[i]);
}

#endif