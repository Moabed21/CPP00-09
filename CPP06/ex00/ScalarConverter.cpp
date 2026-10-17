#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other){(void)other;	return *this;}

ScalarConverter:: ScalarConverter(const ScalarConverter &other){(void)other;}

int check(std::string &str)
{
    return (str == "nan"  || str == "nanf"  ||
            str == "+inf" || str == "+inff" ||
            str == "-inf" || str == "-inff");

}

void toDouble(std::string n)
{
	std::cout << "double: ";
	double d = atof(n.c_str());
	std::cout << std::fixed << std::setprecision(1) << d << std::endl;
}

void toFloat(std::string n)
{
	std::cout << "float: ";
	float f = static_cast<float>(atof(n.c_str()));
	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void toChar(std::string n)
{
	std::cout << "char: ";
	int val = atoi(n.c_str());
	if (val < 0 || val > 127)
		std::cout << "impossible" << std::endl;
	else if (!isprint(val))
		std::cout<<"Non displayable"<<std::endl;
	else
		std::cout<<"'"<< static_cast<char>(val) << "'" <<std::endl;
}

void	toInt(std::string n)
{
	std::cout << "int: ";
	std::cout<< atoi(n.c_str()) <<std::endl;
}

void	ScalarConverter::convert(std::string num)
{
	if (check(num))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		if (num == "nan" || num == "nanf")
		{
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
		}
		else if (num == "+inf" || num == "+inff")
		{
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
		}
		else
		{
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
		}
		return;
	}
	if (num.length() == 1 && !isdigit(num[0]))
	{
		char c = num[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}
	toChar(num);
	toInt(num);
	toFloat(num);
	toDouble(num);
}