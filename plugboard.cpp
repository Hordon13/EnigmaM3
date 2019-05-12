#include "plugboard.h"

void Plugboard::set(std::vector<std::pair<char, char>> plugPairs)
{
    for (auto &plugPair : plugPairs) {
        _plugboard.insert(plugPair);
    }
}

void Plugboard::transcript(std::string &message)
{
    for (char &i : message) {
        if (_plugboard.find(i) != _plugboard.end()) {
            i = _plugboard[i];
        }
    }
}