#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Contact{
    private:
        std::string lastName;
        std::string firstName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkest;

    public:
        //GETTERS
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkest() const;

        //SETTERS
        void setFirstName(const std::string &firstName){this->firstName = firstName; }
        void setLastName(const std::string &lastName){this->lastName = lastName; }
        void setPhoneNumber(const std::string &phoneNumber){this->phoneNumber = phoneNumber; }
        void setNickname(const std::string &nickname){this->nickname = nickname; }
        void setDarkest(const std::string &darkest){this->darkest = darkest; }
};

#endif