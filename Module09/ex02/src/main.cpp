#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	pmergeme;
		pmergeme.parse(argc, argv);
		pmergeme.sort();
		pmergeme.display();
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
