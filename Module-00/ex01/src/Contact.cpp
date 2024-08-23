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
    std::string formatted = str;

    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    while (formatted.length() < 10)
        formatted = " " + formatted;
    return (formatted);
}

void Contact::display_info()
{
    std::cout << "First Name: " << firstName << "\n"
              << "Last Name: " << lastName << "\n"
              << "Nickname: " << nickName << "\n"
              << "Phone Number: " << phoneNumber << "\n"
              << "Darkest Secret: " << darkestSecret << std::endl;
}