#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>

class Contact
{
    public:
        Contact();
        Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
        void display(int index);
        void display_info();
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

        std::string formatField(std::string str);
};

#endif