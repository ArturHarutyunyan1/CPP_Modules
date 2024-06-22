#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "contact.hpp"

class PhoneBook
{
    private:
        Contact *list;
        int size;
        int start;
        int end;
        bool full;
    public:
        PhoneBook(int size);
        ~PhoneBook();
        void add(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);
        void display() const;
};

#endif