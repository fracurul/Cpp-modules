#include "Serializer.hpp"
#include <iostream>

int main()
{
	Serializer::Data	data;
	data.value = "This is how it works";

	std::cout << "Og ptr: " << &data << std::endl;
	std::cout << "Og value: " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized (uintptr_t): " << raw << std::endl;

	Serializer::Data*	restored = Serializer::deserialize(raw);
	std::cout << "Deserialized ptr (ptr restored): " << restored << std::endl;
	std::cout << "Deserialized value (value restored): " << restored->value << std::endl;

	if (restored == &data)
		std::cout << "Serialization successful" << std::endl;
	else
		std::cout << "Serialization failed" << std::endl;

	return (0);
}