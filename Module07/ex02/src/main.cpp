#include "templates.hpp"

int main(void)
{
	try
	{
		std::cout << "=== Test 1: Empty array ===" << std::endl;
		Array<int> empty;
		std::cout << "Size: " << empty.size() << std::endl;

		std::cout << "\n=== Test 2: Array with elements ===" << std::endl;
		Array<int> arr(5);
		std::cout << "Size: " << arr.size() << std::endl;
		std::cout << "Values (default initialized): ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 3: Set values ===" << std::endl;
		for (unsigned int i = 0; i < arr.size(); i++)
			arr[i] = i * 10;
		std::cout << "Values after assignment: ";
		for (unsigned int i = 0; i < arr.size(); i++)
			std::cout << arr[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
		Array<int> copy(arr);
		std::cout << "Copy size: " << copy.size() << std::endl;
		std::cout << "Copy values: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 5: Modify original (copy should not change) ===" << std::endl;
		arr[0] = 999;
		std::cout << "Original arr[0]: " << arr[0] << std::endl;
		std::cout << "Copy arr[0]: " << copy[0] << std::endl;
		std::cout << "Copy values: ";
		for (unsigned int i = 0; i < copy.size(); i++)
			std::cout << copy[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 6: Assignment operator ===" << std::endl;
		Array<int> assigned;
		assigned = arr;
		std::cout << "Assigned size: " << assigned.size() << std::endl;
		std::cout << "Assigned values: ";
		for (unsigned int i = 0; i < assigned.size(); i++)
			std::cout << assigned[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 7: Array with floats ===" << std::endl;
		Array<float> floats(3);
		floats[0] = 1.5f;
		floats[1] = 2.5f;
		floats[2] = 3.5f;
		std::cout << "Float array: ";
		for (unsigned int i = 0; i < floats.size(); i++)
			std::cout << floats[i] << " ";
		std::cout << std::endl;

		std::cout << "\n=== Test 8: Out of bounds (should throw exception) ===" << std::endl;
		std::cout << "Trying to access index 10 in array of size " << arr.size() << std::endl;
		std::cout << arr[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}