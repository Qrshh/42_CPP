#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound
    j->makeSound();
    meta->makeSound();

    //Wrong Animal :
    WrongAnimal* wa = new WrongAnimal();
    WrongAnimal* wc = new WrongCat();
    wa->makeSound();
    wc->makeSound();

    //FREE ALL

    std::cout << "DESTRUCTOR ANIMAL" << std::endl;
    delete meta;
    delete j;
    delete i;

    std::cout << "DESTRUCTOR WRONGCAT" << std::endl;
    delete wa;
    delete wc;

    return 0;
}

