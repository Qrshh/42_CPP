#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string type;
    
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &other);

        virtual ~Animal();
        //overload
        Animal &operator=(const Animal &other);

        //setters and getters
        std::string getType()const;

        void setType(const std::string new_type);

        virtual void makeSound() const;

};


#endif