#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe<std::vector<int> >	pmergeVector;
		pmergeVector.parse(argc, argv);
		pmergeVector.sort();
		pmergeVector.display();

		PmergeMe<std::deque<int> >	pmergeDeque;
		pmergeDeque.parse(argc, argv);
		pmergeDeque.sort();
		pmergeDeque.display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
