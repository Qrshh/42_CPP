#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for(int i = 0; i < this->inventorySize; i ++)
        this->inventory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    *this = other;
}

MateriaSource::~MateriaSource()
{
    for(int i = 0; i < this->inventorySize; i++)
    {
        std::cout << "deleting: " << this->inventory[i] << std::endl;
        if(this->inventory[i])
        {
            delete this->inventory[i];
        }
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if(this != &other)
    {
        for(int i = 0; i < this->inventorySize; i++)
        {
            if(this->inventory[i])
                delete this->inventory[i];
            if(other.inventory[i])
                this->inventory[i] = other.inventory[i];
            else 
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    for(int i = 0; i < this->inventorySize; i++)
    {
        if(this->inventory[i] == NULL)
        {
            std::cout << "MateriaSource learning " << materia->getType() << std::endl;
            this->inventory[i] = materia;
            return ;
        }
    }

    std::cout << "Inventory is full, materia will be deleted" << std::endl;
    delete materia;
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
    for(int i = 0; i < this->inventorySize; i++)
    {
        if(this->inventory[i] != NULL && this->inventory[i]->getType() == type)
            return this->inventory[i];
    }
    std::cout << "Material need to be learned first" << std::endl;
    return NULL;
}