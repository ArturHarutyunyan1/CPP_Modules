#include "phonebook.hpp"

PhoneBook::PhoneBook(int size) : size(size), start(0), end(0), full(false) {
    list = new Contact[size];
}

PhoneBook::~PhoneBook() {
    delete[] list;
}

void PhoneBook::add(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret) {
    list[end] = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    if (full) {
        start = (start + 1) % size;
    }
    end = (end + 1) % size;
    if (end == start) {
        full = true;
    }
}

void PhoneBook::display() const {
    if (start == end && !full) {
        std::cout << "PhoneBook is empty!" << std::endl;
        return;
    }

    int index = start;
    int count = 1;

    while (true) {
        std::cout << "Contact " << count++ << ":\n";
        list[index].display();
        std::cout << "-------------------------\n";

        if (index == end && !full) break;
        index = (index + 1) % size;
        if (index == start && full) break;
    }
}
