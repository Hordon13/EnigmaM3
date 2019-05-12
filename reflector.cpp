#include "reflector.h"

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
    return 0;
}
