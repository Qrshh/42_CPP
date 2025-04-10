#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal();

        //overload
        WrongAnimal &operator=(const WrongAnimal &other);

        void makeSound() const;
};



#endif