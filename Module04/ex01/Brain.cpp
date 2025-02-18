#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    for (int i = 0; i < 100; i++) {
        this->ideas[i] = other.ideas[i];
    }
    std::cout << "Brain copy constructor called " << std::endl;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called " << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain overload operator called " << std::endl;
    if(this != &other)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

void	Brain::setIdea( int index, std::string const &idea )
{
	if (index >= 0 && index < 100)
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return this->ideas[index];
	return NULL;
}