#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Dog")
{
    std::cout << "Wrong cat default constructor called " << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "Wrong cat copy constructor called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if(this != &other)
    {
        this->type = other.type;
    }
    std::cout << "Wrong cat overload operator called " << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "Wrong cat destructor called " << std::endl;
}

void WrongCat::makeSound() const
{
    std::cout << "WrongCat make the sound : bark bark" << std::endl;
}