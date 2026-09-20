#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor Called" << std::endl;
	type = "empty";
}

Animal::Animal(const Animal &other) : type(other.type)
{
    std::cout << "Animal Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    std::cout << "Animal Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor Called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a sound" << std::endl;
}

std::string Animal::getType() const
{
    return type;
}