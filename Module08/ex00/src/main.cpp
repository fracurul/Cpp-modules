#include "templates.hpp"
#include <vector>

int main(void)
{
	std::cout << "=== Test 1: Find element ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);
	try
	{
		std::vector<int>::iterator result = easyfind(vec, 30);
		std::cout << "Success!" << std::endl;
		(void)result;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Number not found ===" << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(vec, 999);
		(void)result;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: First element ===" << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(vec, 10);
		std::cout << "Success!" << std::endl;
		(void)result;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Last element ===" << std::endl;
	try
	{
		std::vector<int>::iterator result = easyfind(vec, 50);
		std::cout << "Success!" << std::endl;
		(void)result;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return (0);
}
