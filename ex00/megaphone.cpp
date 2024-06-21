#include <iostream>
#include <cctype>

class Megaphone
{
    public:
        void capitalize(const std::string &input)
        {
            int i;

            i = 0;
            while (input[i])
            {
                if (input[i] >= 'a' && input[i] <= 'z')
                    std::cout << char(input[i] - 32);
                else
                    std::cout << input[i];
                i++;
            }
        }
};

int main(int argc, char **argv)
{
    Megaphone megaphone;
    int i;

    i = 1;
    if (argc > 1)
    {
        while (argv[i])
        {
            megaphone.capitalize(argv[i]);
            if (argv[i + 1])
                std::cout << " ";
            else
                std::cout << std::endl;
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}