#include "templates.hpp"

int main(void)
{
	std::cout << "=== Test with integers ===" << std::endl;
	int intArr[] = {1, 2, 3, 4, 5};
	::iter(intArr, 5, print<int>);

	std::cout << "\n=== Test with floats ===" << std::endl;
	float floatArr[] = {1.5f, 2.5f, 3.5f, 4.5f};
	::iter(floatArr, 4, print<float>);

	std::cout << "\n=== Test with strings ===" << std::endl;
	std::string stringArr[] = {"Hello", "World", "from", "Template"};
	::iter(stringArr, 4, print<std::string>);

	std::cout << "\n=== Test with const array ===" << std::endl;
	const int constArr[] = {100, 200, 300};
	::iter(constArr, 3, print<int>);

	return (0);
}
