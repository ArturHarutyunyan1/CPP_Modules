#include <iostream>
#include <fstream>

int replace(char **argv, std::string str)
{
    std::ofstream out;
    int pos;

    out.open((std::string(argv[1]) + ".replace").c_str());
    if (out.fail())
        return (1);
    for (int i = 0; i < (int)str.size(); i++)
    {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i)
        {
            out << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else
            out << str[i];
    }
    out.close();
    return (0);
}

int main(int argc, char **argv)
{
    char c;
    std::ifstream in;
    std::string str;
    if (argc != 4)
    {
        std::cout << "Usage: file_name old_word new_word" << std::endl;
        return (1);
    }
    in.open(argv[1]);
    if (in.fail())
    {
        std::cout << "Error: " << argv[1] << "No such file" << std::endl;
        return (1);
    }
    while (!in.eof() && in >> std::noskipws >> c)
        str += c;
    in.close();
    return (replace(argv, str));
}