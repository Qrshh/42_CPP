#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    protected:
        static const int inventorySize = 4;
        AMateria *inventory[inventorySize];
        std::string name;

    public:
        Character(void);
        Character(const std::string &name);
        Character(const Character &other);
        

        Character &operator=(const Character &other);

        virtual ~Character();


        const std::string &getName() const;
        void equip(AMateria *m);
        void unequip(int index);
        void use(int index, ICharacter &target);
};




#endif