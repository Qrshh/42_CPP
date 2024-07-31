#include "Contact.hpp"
#include "Phonebook.hpp"

void search_module(Phonebook &pb)
{
    pb.list();
    pb.search();
    return ;
}

void create_contact(Phonebook &pb)
{
    Contact newContact;
    std::string input;

    std::cout << "first name : ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "last name : ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "nickname : ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "phone number : ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "darkest : ";
    std::getline(std::cin, input);
    newContact.setDarkest(input);

    pb.addContact(newContact);
}

int main(void)
{
    Phonebook pb;
    std::string command;

    while(1)
    {
        std::cout << "Enter a command (ADD, SEARCH, EXIT) : ";
        std::getline(std::cin, command);
        if(command == "ADD")
            create_contact(pb);
        else if (command == "SEARCH")
            search_module(pb);
        else if (command == "EXIT")
            break;
        else 
            std::cout << "INVALID COMMAND ! " << std::endl;
    }
    return (0);
}
