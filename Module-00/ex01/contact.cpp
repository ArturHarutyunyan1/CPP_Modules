#include "contact.hpp"

Contact::Contact() {}

Contact::Contact(const std::string &fn, const std::string &ln, const std::string &nn, const std::string &pn, const std::string &ds)
        : firstName(fn), lastName(ln), nickName(nn), phoneNumber(pn), darkestSecret(ds) {}
void Contact::display() const
{
    std::cout << "First Name: " << firstName << "\n"
            << "Last Name: " << lastName << "\n"
            << "Nickname: " << nickName << "\n"
            << "Phone Number: " << phoneNumber << "\n"
            << "Darkest Secret: " << darkestSecret << "\n";
}