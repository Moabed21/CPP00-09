#include <iostream>
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr<<"Error\n";
		return (1);
	}
	
	ScalarConverter::convert(static_cast<string> (av[1]));
	// ScalarConverter a;

}
