#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int N) : _maxSize(N)
{
}

Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize)
{
}

Span& Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_numbers = other._numbers;
		_maxSize = other._maxSize;
	}
	return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw SpanFullException();
	_numbers.push_back(n);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	unsigned int minSpan = UINT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		unsigned int diff = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
		if (diff < minSpan)
			minSpan = diff;
	}
	return (minSpan);
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());

	return (static_cast<unsigned int>(max - min));
}

unsigned int Span::getSize() const
{
	return (_numbers.size());
}
