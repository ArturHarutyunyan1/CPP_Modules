#include "../include/PhoneBook.hpp"

bool is_valid_phone_number(const std::string &phoneNumber)
{
    size_t i = 0;
    bool hasDigit = false;

    while (i < phoneNumber.size() && (phoneNumber[i] == ' ' || phoneNumber[i] == '\t'))
        ++i;
    if (i < phoneNumber.size() && (phoneNumber[i] == '+' || std::isdigit(phoneNumber[i])))
    {
        ++i;
        while (i < phoneNumber.size())
        {
            if (std::isdigit(phoneNumber[i]))
                hasDigit = true;
            else if (phoneNumber[i] != '-')
                return (false);
            ++i;
        }
        return (phoneNumber.size() >= 4 && hasDigit);
    }
    return (false);
}

void prompt_input(const std::string &prompt, std::string &field, bool (*validator)(const std::string&) = NULL)
{
    do
    {
        std::cout << prompt;
        std::getline(std::cin, field);
        if (field.empty())
            std::cout << "Input can't be empty!\n";
        else if (validator && !validator(field))
            std::cout << "Invald input format!\n";
    }
    while (field.empty() || (validator && !validator(field)));
}


void add_contact(PhoneBook &phoneBook)
{
    std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

    prompt_input("First Name: ", firstName);
    prompt_input("Last Name: ", lastName);
    prompt_input("Nickname: ", nickName);
    prompt_input("Phone Number: ", phoneNumber, is_valid_phone_number);
    prompt_input("Darkest Secret: ", darkestSecret);

    phoneBook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
}

std::string ft_toupper(std::string str)
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = (char)std::toupper(str[i]);
    }
    return (str);
}

void search(PhoneBook &phoneBook)
{
    int index;
    std::string input;
    
    if (phoneBook.count == 0)
    {
        std::cout << "Contact list is empty\n";
        return;
    }
    phoneBook.display_contacts();
    std::cout << "Enter the index of contact\n";
    std::cout << "> ";
    while (1)
    {
        std::getline(std::cin, input);
        if (std::all_of(input.begin(), input.end(), ::isdigit))
        {
            try
            {
                index = std::stoi(input);
                if (std::cin.fail())
                    throw std::invalid_argument("Invalid index\n");
                break;
            }
            catch (std::exception &exc)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Try again!\n";
                std::cout << "> ";
            }
        }
        else
        {
            std::cout << "Invalid input. Try again\n";
            std::cout << "> ";
        }
    }
    phoneBook.search_specific(index);
}

void start(PhoneBook &phoneBook)
{
    std::string choice;

    std::cout << "Welcome to My Awesome PhoneBook!\n";
    do
    {
        std::cout << "\nADD\n"
                  << "SEARCH\n"
                  << "EXIT\n" << std::endl;
        std::cout << "> ";
        std::getline(std::cin, choice);

        if (ft_toupper(choice) == "ADD")
            add_contact(phoneBook);
        else if (ft_toupper(choice) == "SEARCH")
            search(phoneBook);
        else if (ft_toupper(choice) == "EXIT")
        {
            std::cout << "PhoneBook was closed successfully!\n";
            return;
        }
        else
            std::cout << "Invalid choice!\n";
    }
    while (1);
}