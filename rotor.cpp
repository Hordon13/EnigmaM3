#include "rotor.h"

#include <cctype>
#include <iostream>

Rotor::Rotor()
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _ring = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _core = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void Rotor::set(const char &type, char &position, char &ring)
{
    if (type == '1') {
        _wiring = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
        _notch1 = std::make_pair('Q', 'R');
    } else if (type == '2') {
        _wiring = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
        _notch1 = std::make_pair('E', 'F');
    } else if (type == '3') {
        _wiring = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
        _notch1 = std::make_pair('V', 'W');
    } else if (type == '4') {
        _wiring = "ESOVPZJAYQUIRHXLNFTGKDCMWB";
        _notch1 = std::make_pair('J', 'K');
    } else if (type == '5') {
        _wiring = "VZBRGITYUPSDNHLXAWMJQOFECK";
        _notch1 = std::make_pair('Z', 'A');
    } else if (type == '6') {
        _wiring = "JPGVOUMFYQBENHZRDKASXLICTW";
        _notch1 = std::make_pair('Z', 'A');
        _notch2 = std::make_pair('M', 'N');
    } else if (type == '7') {
        _wiring = "NZJHGRCXMYSWBOUFAIVLPEKQDT";
        _notch1 = std::make_pair('Z', 'A');
        _notch2 = std::make_pair('M', 'N');
    } else if (type == '8') {
        _wiring = "FKQHTLXOCBJSPDZRAMEWNIUYGV";
        _notch1 = std::make_pair('Z', 'A');
        _notch2 = std::make_pair('M', 'N');
    }

    if (isdigit(ring)) {
        ring = _alphabet.at(ring - '1');
    }

    while (_ring.at(0) != ring) {
        _ring += _ring.at(0);
        _ring.erase(0, 1);
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
    _ring += _ring.at(0);
    _ring.erase(0, 1);
    _core += _core.at(0);
    _core.erase(0, 1);

    _step = _ring.at(0) == _notch1.first || _ring.at(0) == _notch2.first;
    _stepDouble = _ring.at(0) == _notch1.second || _ring.at(0) == _notch2.second;
}

int Rotor::process(int signal)
{
    return 0;
}