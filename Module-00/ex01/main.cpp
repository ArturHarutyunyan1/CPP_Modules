#include "phonebook-app.hpp"

using namespace std;

std::string get_input(const std::string &prompt)
{
    std::string input;

    while (true)
    {
        std::cout << prompt;
        getline(cin, input);

        if (!input.empty())
            break;
        std::cout << "Invalid input! Please, try again\n";
    }
    return (input);
}

int pb(std::string &input, PhoneBook phonebook)
{
    while (true)
    {
        std::cout << "Hey! Welcome to my very awesome PhoneBook!!!" << std::endl;
        std::cout << "Select one of the options below\n" << std::endl;
        std::cout << "1 - ADD" << std::endl;
        std::cout << "2 - SEARCH" << std::endl;
        std::cout << "3 - EXIT\n" << std::endl;
        getline(cin, input);
        if (capitalize(input) == "ADD")
        {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

            firstName = get_input("First Name: ");
            lastName = get_input("Last Name: ");
            nickName = get_input("Nickname: ");
            while (!is_number(phoneNumber))
            {
                phoneNumber = get_input("Phone Number: ");
                if (!is_number(phoneNumber))
                    std::cout << "Invalid phone number! Try again!\n";
            }
            darkestSecret = get_input("Darkest Secret: ");
            phonebook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
        }
        else if (capitalize(input) == "SEARCH")
        {
            // To be handled
        }
    }
}

int main(int argc, char **argv) {
    PhoneBook phonebook(8);
    string input;
    pb(input, phonebook);
    return (0);
}
