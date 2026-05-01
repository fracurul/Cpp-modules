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

template<typename Container>
class	PmergeMe
{
	private:
		Container			_data;
		Container			_dataBefore;
		double				_time;

		Container			fordJohnson(Container arr);
		int					binarySearch(const Container& arr, int value);

		std::vector<int>	getJacobsthalOrder(size_t size);
		std::vector<int>	generateJacobsthalNumbers(size_t size);

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

#include "../src/PmergeMe.cpp"

#endif