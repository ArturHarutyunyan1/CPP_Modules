#include "phonebook-app.hpp"

bool is_number(const std::string &str)
{
    int i;

    i = 0;
    while ((i < str.length()) && (str[i] == ' ' || str[i] == '\t'))
        i++;
    while ((i < str.length()) && (str[i] == '+' || str[i] == '-'))
        i++;
    if (i == str.length() || !isdigit(str[i]))
        return (false);
    while (i < str.length())
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

std::string capitalize(std::string &input)
{
    int i;

    i = 0;
    while (input[i])
    {
        if (input[i] >= 'a' && input[i] <= 'z')
            input[i] -= 32;
        i++;
    }
    return (input);
}
        