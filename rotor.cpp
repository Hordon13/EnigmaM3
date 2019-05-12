#include "rotor.h"

#include <cctype>
#include <iostream>

Rotor::Rotor()
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _ring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _core = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _notch2 = -1;
}

void Rotor::set(const char &type, char &position, char &ring)
{
    if (type == '1') {
        _wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        _notch1 = 16;
    } else if (type == '2') {
        _wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        _notch1 = 4;
    } else if (type == '3') {
        _wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        _notch1 = 21;
    } else if (type == '4') {
        _wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        _notch1 = 9;
    } else if (type == '5') {
        _wiring = "VZBRGITYUPSDNHLXAWMJQOFECK";
        _notch1 = 25;
    } else if (type == '6') {
        _wiring = "JPGVOUMFYQBENHZRDKASXLICTW";
        _notch1 = 25;
        _notch2 = 12;
    } else if (type == '7') {
        _wiring = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        _notch1 = 25;
        _notch2 = 12;
    } else if (type == '8') {
        _wiring = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        _notch1 = 25;
        _notch2 = 12;
    }

    if (isdigit(ring)) {
        ring = _alphabet.at(ring - '1');
    }

    while (_ring.at(0) != ring) {
        _ring += _ring.at(0);
        _ring.erase(0);
    }

    if (isdigit(position)) {
        position = _alphabet.at(position - '1');
    }

    while (_ring.at(0) != position) {
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