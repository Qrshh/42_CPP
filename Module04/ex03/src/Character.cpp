#include "Character.hpp"

Character::Character() : name("Unnamed")
{
    for(int i = 0; i < inventorySize ; i++)
        this->inventory[i] = NULL;

    std::cout << "Character default constructor called " << std::endl;
}

Character::Character(const std::string &name) : name(name)
{
    for(int i = 0; i < inventorySize ; i++)
        this->inventory[i] = NULL;

    std::cout << "Character constructor called " << std::endl;
}

Character::Character(const Character &other)
{
    *this = other;

    std::cout << "Character copy constructor called " << std::endl;
}

Character::~Character()
{
    for(int i = 0; i < inventorySize; i++)
        delete this->inventory[i];
}

Character &Character::operator=(const Character &other)
{
    if(this != &other)
    {
        this->name = other.name;
        for(int i = 0; i < inventorySize; i++)
        {
            if(this->inventory[i])
                delete this->inventory[i];
            if(other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else 
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

const std::string &Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria *m)
{
    if(!m)
        return ;
    
    for(int i = 0; i < inventorySize; i++)
    {
        if(this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            std::cout << this->name << " equips " << m->getType() << " in " << i << std::endl;
            return ;
        }

    }
    std::cout << this->name << " cannot equip " << m->getType() << " , because inventory is full " << std::endl;
    delete m;
}

void Character::unequip(int index)
{
    if(index >= 0 && index < this->inventorySize && this->inventory[index])
    {
        std::cout << this->name << " unequips " << this->inventory[index]->getType() << " (" << index << ")" << std::endl;
        this->inventory[index] = NULL;
    }
}

void Character::use(int index, ICharacter &target)
{
    if(index >= 0 && index < this->inventorySize && this->inventory[index])
    {
        this->inventory[index]->use(target);
    }
    else 
        std::cout << this->name << " doesn't do anything " << std::endl;
}

