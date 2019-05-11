#include <iostream>

#include "model.h"

int main()
{
    Model enigma;
    std::cout << "Enter a message: " << std::endl;
    std::string input;
    std::cin >> input;
    std::cout << enigma.encrypt(input) << std::endl;

    return 0;
}