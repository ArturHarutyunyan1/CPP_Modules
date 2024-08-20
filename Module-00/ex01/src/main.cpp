#include "../include/Utils.hpp"

int main(int argc, char **argv)
{
    (void)argv;
    if (argc != 1)
    {
        std::cout << "Error\nInvalid arguments!\nUsage - ./phonebook\n";
        return (1);
    }
    PhoneBook phoneBook;
    start(phoneBook);
    return (0);
}