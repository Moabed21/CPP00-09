#include "Serializer.hpp"

int main()
{
	Data a(42, "Module06", 3.14159);

	uintptr_t raw = Serializer::serialize(&a);
	Data* deserialized = Serializer::deserialize(raw);

	std::cout << "Original address:      " << &a << std::endl;
	std::cout << "Serialized raw value:  " << raw << std::endl;
	std::cout << "Deserialized address:  " << deserialized << std::endl;

	if (deserialized == &a)
		std::cout << "Comparison: Success! Deserialized pointer compares equal to original pointer." << std::endl;
	else
		std::cout << "Comparison: Failure! Deserialized pointer does NOT match original pointer." << std::endl;

	std::cout << "Data content verification: id=" << deserialized->id
			  << ", name=\"" << deserialized->name
			  << "\", value=" << deserialized->value << std::endl;

	return 0;
}
