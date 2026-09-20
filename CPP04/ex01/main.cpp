#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *array[10];

    int size = 1;
    for (int i = 0; i <size; i++)
    {
        array[i] = new Dog();
    }
    std::cout<<std::endl;
    for (int i = size; i < size * 2; i++)
    {
        array[i] = new Cat();
    }
    std::cout<<std::endl;
    for (int i = 0; i < size * 2; i++)
    {
        delete array[i];
    }
    std::cout<<std::endl;
    
    
    return 0;
}