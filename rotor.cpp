#include "rotor.h"

Rotor::Rotor()
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _ring = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
             'U', 'V', 'W', 'X', 'Y', 'Z'};
    _core = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
             'U', 'V', 'W', 'X', 'Y', 'Z'};
    _notch2 = -1;
}

void Rotor::setRotor(const std::string &type, const std::string &position, const std::string &ring)
{
    if (type == "1") {
        _wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        _notch1 = 0;
    } else if (type == "2") {
        _wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        _notch1 = 0;
    } else if (type == "3") {
        _wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        _notch1 = 0;
    } else if (type == "4") {
        _wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        _notch1 = 0;
    } else if (type == "5") {
        _wiring = "VZBRGITYUPSDNHLXAWMJQOFECK";
        _notch1 = 0;
    } else if (type == "6") {
        _wiring = "JPGVOUMFYQBENHZRDKASXLICTW";
        _notch1 = 0;
        _notch2 = 0;
    } else if (type == "7") {
        _wiring = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        _notch1 = 0;
        _notch2 = 0;
    } else if (type == "8") {
        _wiring = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        _notch1 = 0;
        _notch2 = 0;
    }
}

void Rotor::turn()
{

}

int Rotor::process(int signal)
{
    return 0;
}
