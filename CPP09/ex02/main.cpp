#include "PmergeMe.hpp"

#include <exception>
#include <iomanip>
#include <iostream>

template <typename Container>
static void printSequence(const std::string &label, const Container &c)
{
	std::cout << label;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		PmergeMe sorter;
		sorter.parse(argc, argv);

		double vecTime = sorter.sortVector();
		double deqTime = sorter.sortDeque();

		printSequence("Before:", sorter.getInput());
		printSequence("After: ", sorter.getVector());

		std::size_t n = sorter.getInput().size();
		std::cout << std::fixed << std::setprecision(5);
		std::cout << "Time to process a range of " << n
				  << " elements with std::vector : " << vecTime << " us" << std::endl;
		std::cout << "Time to process a range of " << n
				  << " elements with std::deque  : " << deqTime << " us" << std::endl;
	}
	catch (const std::exception &)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
