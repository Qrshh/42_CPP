#include "Dog.hpp"
#include "Animal.hpp"
#include "Cat.hpp"

int main()
{
    /*Copy and delete*/
    {
        Dog basic;
        {
            Dog tmp = basic; //copy constructor
        }
    }
        std::cout << "CHECK\n";

    const int size = 10;
    Animal* animals[size];

    for (int i = 0; i < size / 2; ++i)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; ++i)
        animals[i] = new Cat();

    for (int i = 0; i < size; ++i)
        delete animals[i];

    // TEST: Copie profonde pour Dog
    std::cout << "\n--- Test de copie profonde (Dog) ---\n";
    Dog dog1;
    dog1.setIdea(0, "Chase the ball");
    Dog dog2 = dog1;
    dog2.setIdea(1, "Sleep instead");
    std::cout << "Dog1 idea: " << dog1.getIdea(0) << "\n";
    std::cout << "Dog2 idea: " << dog2.getIdea(0) << "\n";

    // TEST: Copie profonde pour Cat
    std::cout << "\n--- Test de copie profonde (Cat) ---\n";
    Cat cat1;
    cat1.setIdea(0, "Catch the mouse");
    Cat cat2 = cat1; 
    cat2.setIdea(1, "Sleep instead");
    std::cout << "Cat1 idea: " << cat1.getIdea(0) << "\n";
    std::cout << "Cat2 idea: " << cat2.getIdea(0) << "\n";

    return 0;
}
