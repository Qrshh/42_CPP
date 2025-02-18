#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory adress of the string    : " << &string << std::endl;
    std::cout << "Memory adress of the pointer   : " << stringPTR << std::endl;
    std::cout << "Memory adress of the reference : " << &stringREF << std::endl;

    std::cout << "Value of the string    : " << string << std::endl;
    std::cout << "Value of the pointer   : " << *stringPTR << std::endl;
    std::cout << "Value of the reference : " << stringREF << std::endl;

    return 0;
}