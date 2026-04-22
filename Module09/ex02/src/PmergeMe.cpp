#include "PmergeMe.hpp"

int	PmergeMe::binarySearchVector(const std::vector<int>& arr, int value)
{
	int	left = 0;
	int	right = arr.size();

	while (left < right)
	{
		int	mid = left + ((right - left) / 2);
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

int	PmergeMe::binarySearchDeque(const std::deque<int>& arr, int value)
{
	int	left = 0;
	int	right = arr.size();

	while (left < right)
	{
		int	mid = left + ((right - left) / 2);
		if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

std::vector<int>	PmergeMe::fordJohnsonVector(std::vector<int> arr)
{
	if (arr.size() <= 1)
		return (arr);
	std::vector<int>	mainChain;
	std::vector<int>	pendChain;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			mainChain.push_back(arr[i + 1]);
			pendChain.push_back(arr[i]);
		}
		else
		{
			mainChain.push_back(arr[i]);
			pendChain.push_back(arr[i + 1]);
		}
	}
	if (arr.size() % 2 == 1)
		pendChain.push_back(arr[arr.size() - 1]);
	mainChain = fordJohnsonVector(mainChain);
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		int	pos = binarySearchVector(mainChain, pendChain[i]);
		mainChain.insert(mainChain.begin() + pos, pendChain[i]);
	}
	return (mainChain);
}

std::deque<int>	PmergeMe::fordJohnsonDeque(std::deque<int> arr)
{
	if (arr.size() <= 1)
		return (arr);
	std::deque<int>	mainChain;
	std::deque<int>	pendChain;

	for (size_t i = 0; i + 1 < arr.size(); i += 2)
	{
		if (arr[i] < arr[i + 1])
		{
			mainChain.push_back(arr[i + 1]);
			pendChain.push_back(arr[i]);
		}
		else
		{
			mainChain.push_back(arr[i]);
			pendChain.push_back(arr[i + 1]);
		}
	}
	if (arr.size() % 2 == 1)
		pendChain.push_back(arr[arr.size() - 1]);
	mainChain = fordJohnsonDeque(mainChain);
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		int	pos = binarySearchDeque(mainChain, pendChain[i]);
		mainChain.insert(mainChain.begin() + pos, pendChain[i]);
	}
	return (mainChain);
}

void	PmergeMe::sortVector()
{
	struct timeval	start, end;
	gettimeofday(&start, NULL);

	_vectorData = fordJohnsonVector(_vectorData);

	gettimeofday(&end, NULL);
	_vectorTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

void	PmergeMe::sortDeque()
{
	struct timeval	start, end;
	gettimeofday(&start, NULL);

	_dequeData = fordJohnsonDeque(_dequeData);

	gettimeofday(&end, NULL);
	_dequeTime = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

PmergeMe::PmergeMe() : _vectorTime(0.0), _dequeTime(0.0) {}

PmergeMe::PmergeMe(const PmergeMe& copy) : _vectorData(copy._vectorData), _dequeData(copy._dequeData) {}

PmergeMe&	PmergeMe::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_vectorData = copy._vectorData;
		_dequeData = copy._dequeData;
	}
	return (*this);
}

PmergeMe::~PmergeMe() {}

bool	PmergeMe::isPositiveNumber(const std::string& str)
{
	if (str.empty() || str[0] == '-')
		return (false);

	std::istringstream	iss(str);
	int					num;
	char				extra;

	return ((iss >> num) && !(iss >> extra) && num > 0);
}

void	PmergeMe::parse(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error: not enought arguments");

	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		if (!PmergeMe::isPositiveNumber(arg))
			throw std::invalid_argument("Error");

		int	num = atoi(arg.c_str());
		_vectorData.push_back(num);
		_dequeData.push_back(num);
	}
	_vectorBefore = _vectorData;
	_dequeBefore = _dequeData;
}

void	PmergeMe::sort()
{
	PmergeMe::sortVector();
	PmergeMe::sortDeque();
}

void	PmergeMe::display() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vectorBefore.size(); i++)
	{
		std::cout << _vectorBefore[i];
		if (i < _vectorBefore.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < _vectorData.size(); i++)
	{
		std::cout << _vectorData[i];
		if (i < _vectorData.size() - 1)
			std::cout << " ";
		}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _vectorData.size()
		<< " elements with std::vector : " << _vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _dequeData.size()
		<< " elements with std::deque : " << _dequeTime << " us" << std::endl;
}