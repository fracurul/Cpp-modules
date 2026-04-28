#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int n) : _size(n) {}

Span::Span(const Span& copy) : _size(copy._size), _numbers(copy._numbers) {}

Span&	Span::operator=(const Span& copy)
{
	if (this != &copy)
	{
		_size = copy._size;
		_numbers = copy._numbers;
	}
	return (*this);
}

Span::~Span() {}

void	Span::addNumber(int num)
{
	if (_numbers.size() >= _size)
		throw std::out_of_range("Span is full");
	_numbers.push_back(num);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Error: Cannot find span with less than 2 numbers");

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	int	res = INT_MAX;
	for (size_t i = 0; i < sorted.size() - 1; i++)
	{
		int	diff = std::abs(sorted[i] - sorted[i + 1]);
		if (diff < res)
			res = diff;
	}
	return (res);
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw std::runtime_error("Error: Cannot find span with less than 2 numbers");
	int	max = *std::max_element(_numbers.begin(), _numbers.end());
	int	min = *std::min_element(_numbers.begin(), _numbers.end());
	return (max - min);
}