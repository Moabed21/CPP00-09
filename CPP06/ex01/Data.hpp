#pragma once
#include <string>

class Data 
{
	public:
		int id;
		std::string name;
		double value;

		Data();
		Data(int id, const std::string &name, double value);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();
};
