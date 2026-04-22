#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	_vectorData;
		std::deque<int>		_dequeData;
		std::vector<int>	_vectorBefore;
		std::deque<int>		_dequeBefore;
		double				_vectorTime;
		double				_dequeTime;

		std::vector<int>	fordJohnsonVector(std::vector<int> arr);
		int					binarySearchVector(const std::vector<int>& arr, int value);

		std::deque<int>		fordJohnsonDeque(std::deque<int> arr);
		int					binarySearchDeque(const std::deque<int>& arr, int value);

		void				sortVector();
		void				sortDeque();
	public:
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		PmergeMe&	operator=(const PmergeMe& copy);
		~PmergeMe();

		bool	isPositiveNumber(const std::string& str);
		void	parse(int argc, char** argv);
		void	sort();
		void	display() const;
};

#endif