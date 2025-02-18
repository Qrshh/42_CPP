#include "AMateria.hpp"

AMateria::AMateria() : type("untyped")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string &type) : type(type)
{
    std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria copy constructor called " << std::endl;
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria overload operator called " << std::endl;
    if(this != &other)
    {
        this->type = other.type;
    }
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called " << std::endl;
}

const std::string &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    std::cout << "Virtual function so who cares abt what it's printing there ??" << std::endl;    
}