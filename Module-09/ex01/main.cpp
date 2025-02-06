#include "RPN.hpp"

int main(int argc, char **argv) {
    try {
        if (argc != 2)
            throw std::runtime_error("Error");
        RPN rpn;
        rpn.calculator(argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << '\n';
        return 1;
    }
}