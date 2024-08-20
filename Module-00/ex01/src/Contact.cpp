#include "../include/Contact.hpp"

Contact::Contact() : firstName(""), lastName(""), nickName(""), phoneNumber(""), darkestSecret("") {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
            : firstName(fn), lastName (ln), nickName(nn), phoneNumber(pn), darkestSecret(ds) {}

void Contact::display(int index)
{
    std::cout << formatField(std::to_string(index)) << "|"
            << formatField(firstName) << "|"
            << formatField(lastName) << "|"
            << formatField(nickName) << std::endl;
}

std::string Contact::formatField(std::string str)
{
    std::ostringstream oss;

    if (str.length() > 10)
        oss << std::setw(10) << std::right << str.substr(0, 9) + ".";
    else
        oss << std::setw(10) << std::right << str;
    return (oss.str());
}

void Contact::display_info()
{
    std::cout << "First Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n"
              << "Nickname: " << nickName << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "Darkest Secret: " << darkestSecret << std::endl;
}