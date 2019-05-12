#include <iostream>

#include "model.h"

int main()
{
    Model enigma;
    std::cout << "Enter a message: " << std::endl;
    std::string input = "helloworld";
    //std::cin >> input;
    std::cout << enigma.encrypt(input) << std::endl;

    return 0;
}