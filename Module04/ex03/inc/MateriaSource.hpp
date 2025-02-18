#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    protected:
        static const int inventorySize = 4;
        AMateria *inventory[inventorySize];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &other);
        MateriaSource &operator=(const MateriaSource &other);

        virtual ~MateriaSource();

        void learnMateria(AMateria *m);
        AMateria *createMateria(const std::string &type);
};


#endif