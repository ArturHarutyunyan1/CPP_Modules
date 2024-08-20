#include "../include/PhoneBook.hpp"

PhoneBook::PhoneBook() : oldest(0), count(0) {}

void PhoneBook::add(std::string &fn, std::string &ln, std::string &nn, std::string &pn, std::string &ds)
{
    if (oldest == 8)
        oldest = 0;
    if (count < 8)
    {
        contacts[count] = Contact(fn, ln, nn, pn, ds);
        count++;
    }
    else
    {
        contacts[oldest] = Contact(fn, ln, nn, pn, ds);
        oldest++;
    }
    std::cout << "Contact addedd successfully" << std::endl;
}

void PhoneBook::display_contacts()
{
    std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;
    for (int i = 0; i < count; ++i)
    {
        contacts[i].display(i);
        std::cout << "-------------------------------------------" << std::endl;
    }
}

void PhoneBook::search_specific(int index)
{
    if (index >= 0 && index < count)
    {
        contacts[index].display_info();
    }
    else
        std::cout << "Invalid index!\n";
}