#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *ptr = &str;
    std::string &ref = str;
    
    std::cout << "Memory address of string - " << &str << "\n"
              << "Memory address of pointer - "<< ptr << "\n"
              << "Memory address of reference - " << &ref << "\n"
              << "Value of string - " << str << "\n"
              << "Value of string ptr - " << *ptr << "\n"
              << "Value of string reference - " << ref << std::endl;
    return (0);
}