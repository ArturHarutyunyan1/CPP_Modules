#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact contacts[8];
        int count;
        int oldest;
    public:
        PhoneBook();
        void add(std::string &fn, std::string &ln, std::string &nn, std::string &pn, std::string &ds);
        void display_contacts();
        void search_specific(int index);
};


#endif