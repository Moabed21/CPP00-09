#include "Data.hpp"

Data::Data() : id(0), name(""), value(0.0)
{
}

Data::Data(int id, const std::string &name, double value) : id(id), name(name), value(value)
{
}

Data::Data(const Data &other) : id(other.id), name(other.name), value(other.value)
{
}

Data &Data::operator=(const Data &other)
{
	if (this != &other)
	{
		this->id = other.id;
		this->name = other.name;
		this->value = other.value;
	}
	return *this;
}

Data::~Data()
{
}