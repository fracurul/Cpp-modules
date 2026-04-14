#ifndef	SPAN_HPP
#define	SPAN_HPP

#include <vector>			  // std::vector.
#include <algorithm>		 // std::max_element, std::min_element.
#include <iostream>			// std:cout.
#include <cstdlib>		   // std::abs y rand.
#include <climits>		  // INT_MAX.
#include <ctime>		 // time().
#include <stdexcept>	// std::out_of_range, std::runtime_error.

class	Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_numbers;

	public:
		Span();
		Span(unsigned int n);
		~Span();

		void	addNumber(int num);
		template<typename Iterator>
		void	addNumberLoop(Iterator begin, Iterator end);
		int		shortestSpan();
		int		longestSpan();
};

#include "Span.tpp"

#endif