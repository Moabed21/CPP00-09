#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Default Constructor Called" << std::endl;
	brain = new Brain();
}

// deep copy
Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog Copy Constructor Called" << std::endl;
	this->brain = new Brain(*other.brain);
}

// deep copy
Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Copy Assignment Operator Called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
		if (this->brain)
			delete brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor Called" << std::endl;
	delete brain;
}

void Dog::makeSound() const
{
	std::cout << "Hawwwww" << std::endl;
}

std::string Dog::getType() const
{
	return type;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}