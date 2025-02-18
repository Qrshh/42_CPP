#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default cat constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat overload operator = called " << std::endl;
    if(this != &other)
    {
        this->type = other.type;
        delete brain;
        this->brain = new Brain(*other.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called " << std::endl;
    delete this->brain;
}


void Cat::makeSound() const
{
    std::cout << "Meow Meow" << std::endl;
}

void Cat::setIdea(int index, const std::string &idea)
{
    this->brain->setIdea(index, idea);
}

std::string Cat::getIdea(int index) const
{
    return(this->brain->getIdea(index));
}