#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
    public:
        Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
        void display(int index);
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

        std::string formatField(std::string str);
};

#endif