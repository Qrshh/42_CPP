#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
    std::cout << "Wrong animal default constructor called " << std::endl;
    this->type = "Wrong Default Animal";
}

WrongAnimal::WrongAnimal(std::string type)
{
    std::cout << "Wrong animal constructor called " << std::endl;
    this->type = type;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "Wrong animal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Wrong animal destructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Wrong animal overload operator = called " << std::endl;
    return *this;
}

void WrongAnimal::makeSound() const
{
    std::cout << "Wrong animal make a sound" << std::endl;
}