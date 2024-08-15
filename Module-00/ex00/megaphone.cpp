#include <iostream>

void capitalize(char **argv)
{
    for (int i = 1; argv[i]; i++)
    {
        for (int j = 0; argv[i][j]; j++)
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z')
                argv[i][j] -= 32;
            std::cout << argv[i][j];
        }
        if (argv[i + 1])
            std::cout << " ";
        if (!argv[i + 1])
            std::cout << "\n";
    }
}

int main(int argc, char **argv)
{
    if (argc <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
        return (0);
    }
    capitalize(argv);
    return (0);
}