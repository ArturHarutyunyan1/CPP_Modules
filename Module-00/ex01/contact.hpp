#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
    public:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

        Contact();
        Contact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds);
        void display() const;
};

#endif