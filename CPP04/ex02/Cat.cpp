#include "Cat.hpp"

Cat::Cat() : Animal()
{
    this->type = "Cat";
    std::cout << "Cat Default Constructor Called" << std::endl;
    brain = new Brain();
}
// deep copy
Cat::Cat(const Cat &other) : Animal(other)
{
    std::cout << "Cat Copy Constructor Called" << std::endl;
    this->brain = new Brain(*other.brain);
}

// deep copy
Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Copy Assignment Operator Called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor Called" << std::endl;
    delete brain;
}

void Cat::makeSound() const
{
    std::cout << "mewww" << std::endl;
}

std::string Cat::getType() const
{
    return type;
}

Brain *Cat::getBrain() const
{
    return this->brain;
}

