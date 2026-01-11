#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span();
		Span(unsigned int N);
		Span(const Span& other);
		Span &operator=(const Span& other);
		~Span();

		void			addNumber(int n);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		unsigned int	getSize() const;

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end)
		{
			while (begin != end)
			{
				addNumber(*begin);
				++begin;
			}
		}

		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Span is full, cannot add more numbers";
				}
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Not enough numbers to find a span";
				}
		};
};

#endif