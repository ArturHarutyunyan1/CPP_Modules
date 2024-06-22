#include "phonebook-app.hpp"

using namespace std;

int main(int argc, char **argv) {
    PhoneBook phonebook(8);
    string input;

    while (true) {
        std::cout << "Hey! Welcome to my very awesome PhoneBook!!!" << std::endl;
        std::cout << "Select one of the options below\n" << std::endl;
        std::cout << "1 - ADD" << std::endl;
        std::cout << "2 - SEARCH" << std::endl;
        std::cout << "3 - EXIT\n" << std::endl;
        getline(cin, input);

        if (input == "1" || input == "ADD") {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

            std::cout << "First Name: ";
            getline(cin, firstName);
            std::cout << "Last Name: ";
            getline(cin, lastName);
            std::cout << "Nickname: ";
            getline(cin, nickName);
            std::cout << "Phone Number: ";
            getline(cin, phoneNumber);
            std::cout << "Darkest Secret: ";
            getline(cin, darkestSecret);
            phonebook.add(firstName, lastName, nickName, phoneNumber, darkestSecret);
        } else if (input == "2" || input == "SEARCH") {
            phonebook.display();
        } else if (input == "3" || input == "EXIT") {
            break;
        } else {
            std::cout << "Invalid option. Please try again." << std::endl;
        }
    }

    return 0;
}
