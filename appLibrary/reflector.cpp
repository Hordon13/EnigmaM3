#include "reflector.h"

Reflector::Reflector()
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
}

void Reflector::set(const char &type)
{
    if (type == 'B') {
        _wiring = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    } else if (type == 'C') {
        _wiring = "FVPJIAOYEDRZXWGCTKUQSBNMHL";
    }
}

int Reflector::reverse(int signal)
{
    return _alphabet.find(_wiring.at(signal));
}
