#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void print(const T& x)
{
	std::cout << x << std::endl;
}

void increment(int& x)
{
	++x;
}

int main(void)
{
	// Case 1: Non-const array with non-const reference function (mutation)
	std::cout << "--- Case 1: Non-const int array (increment) ---" << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	::iter(arr, 5, increment);
	::iter(arr, 5, print<int>);

	// Case 2: Const array with const reference function
	std::cout << "--- Case 2: Const int array (read-only) ---" << std::endl;
	const int c_arr[] = {10, 20, 30};
	::iter(c_arr, 3, print<int>);

	// Case 3: Different data type (std::string) with instantiated template function
	std::cout << "--- Case 3: String array ---" << std::endl;
	std::string words[] = {"Hello", "42", "World"};
	::iter(words, 3, print<std::string>);

	return 0;
}