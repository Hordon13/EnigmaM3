#include "rotor.h"

Rotor::Rotor()
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _ring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _core = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _notch2 = -1;
}

void Rotor::set(const std::string &type, std::string &position, std::string &ring)
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

    if (isdigit(ring.at(0))) {
        ring = _alphabet.at(std::stoi(ring) - 1);
    }

    while (_ring.at(0) != ring.at(0)) {
        _ring += _ring.at(0);
        _ring.erase(0);
    }

    if (isdigit(position.at(0))) {
        position = _alphabet.at(std::stoi(position) - 1);
    }

    while (_ring.at(0) != position.at(0)) {
        turn();
    }
}

void Rotor::turn()
{


}

int Rotor::process(int signal)
{
    return 0;
}
