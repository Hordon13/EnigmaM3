#include <iostream>

#include "model.h"

int main()
{
    std::cout << "Configure enigma... " << std::endl;
    std::cout << "Example: 368/UZV/AHM/B/AN.EZ.HK.IJ.LR.MQ.OT.PV.SW.UX" << std::endl;
    std::string config;
    std::cin >> config;

    if (config == ".") {
        config = "368/UZV/AHM/B/AN.EZ.HK.IJ.LR.MQ.OT.PV.SW.UX";
    }

    Model enigma(config);

    while (true) {
        std::cout << std::endl;
        std::cout << "Enter a message: ";
        std::string input;
        std::cin >> input;
        if (input == "@exit") {
            break;
        }
        std::cout << enigma.encrypt(input) << std::endl;
    }

    return 0;
}