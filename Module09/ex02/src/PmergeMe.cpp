#include "PmergeMe.hpp"

template<typename Container>
int	PmergeMe<Container>::binarySearch(const Container& arr, int value)
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

template<typename Container>
Container	PmergeMe<Container>::fordJohnson(Container arr)
{
	if (arr.size() <= 1)
		return (arr);
	Container	mainChain;
	Container	pendChain;

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
	mainChain = fordJohnson(mainChain);
	std::vector<int>	insertionOrder = getJacobsthalOrder(pendChain.size());
	for (size_t i = 0; i < pendChain.size(); i++)
	{
		int	idx = insertionOrder[i];
		int	pos = binarySearch(mainChain, pendChain[idx]);
		mainChain.insert(mainChain.begin() + pos, pendChain[idx]);
	}
	return (mainChain);
}


template<typename Container>
std::vector<int>	PmergeMe<Container>::generateJacobsthalNumbers(size_t size)
{
	std::vector<int>	js;
	if (size >= 1)
		js.push_back(0);
	if (size >= 2)
		js.push_back(1);
	while (js.size() < size)
	{
		int	prev = js[js.size() -1];
		int pPrev = js[js.size() - 2];
		js.push_back(prev + (2 * pPrev));
	}
	return (js);
}

template<typename Container>
std::vector<int>	PmergeMe<Container>::getJacobsthalOrder(size_t size)
{
	std::vector<int>	js = generateJacobsthalNumbers(size + 5);
	std::vector<int>	order;
	std::vector<bool>	inserted(size, false);

	for (size_t i = 2; i < js.size() && order.size() < size; i++)
	{
		int	pos = js[i] - 1;
		while (pos >= 0 && pos < (int)size)
		{
			if (!inserted[pos])
			{
				order.push_back(pos);
				inserted[pos] = true;
			}
			pos = pos - js[i - 1];
		}
	}
	for (size_t i = 0; i < size; i++)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	return (order);
}

template<typename Container>
void	PmergeMe<Container>::sort()
{
	struct timeval	start, end;
	gettimeofday(&start, NULL);

	_data = fordJohnson(_data);

	gettimeofday(&end, NULL);
	_time = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);
}

template<typename Container>
PmergeMe<Container>::PmergeMe() : _time(0.0) {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& copy) : _data(copy._data), _dataBefore(copy._dataBefore), _time(copy._time) {}

template<typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe& copy)
{
	if (this != &copy)
	{
		_data = copy._data;
		_dataBefore = copy._dataBefore;
		_time = copy._time;
	}
	return (*this);
}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
bool	PmergeMe<Container>::isPositiveNumber(const std::string& str)
{
	if (str.empty() || str[0] == '-')
		return (false);

	std::istringstream	iss(str);
	int					num;
	char				extra;

	return ((iss >> num) && !(iss >> extra) && num > 0);
}

template<typename Container>
void	PmergeMe<Container>::parse(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("Error: not enought arguments");

	for (int i = 1; i < argc; i++)
	{
		std::string	arg = argv[i];
		if (!isPositiveNumber(arg))
			throw std::invalid_argument("Error");

		int	num = atoi(arg.c_str());
		_data.push_back(num);
	}
	_dataBefore = _data;
}

template<typename Container>
void	PmergeMe<Container>::display() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _dataBefore.size(); i++)
	{
		std::cout << _dataBefore[i];
		if (i < _dataBefore.size() - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
	std::cout << "After: ";
	for (size_t i = 0; i < _data.size(); i++)
	{
		std::cout << _data[i];
		if (i < _data.size() - 1)
			std::cout << " ";
		}
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _data.size()
		<< " elements with this container : " << _time << " us" << std::endl;
}