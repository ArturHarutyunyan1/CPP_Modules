#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPtr = &str;
    std::string &stringRef = str;
    
    std::cout << "Memory address of string - " << &str << "\n"
              << "Memory address of pointer - "<< stringPtr << "\n"
              << "Memory address of stringReference - " << &stringRef << "\n"
              << "Value of string - " << str << "\n"
              << "Value of string stringPtr - " << *stringPtr << "\n"
              << "Value of string stringReference - " << stringRef << std::endl;
    return (0);
}