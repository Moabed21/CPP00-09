#pragma once
#include <iostream>
#include <iomanip> 
#include <cstdlib>

class ScalarConverter
{
	private:
		
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &other);
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter();
	public:
		static void	convert(std::string num);
};

