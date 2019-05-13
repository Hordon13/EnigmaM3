#include "model.h"

#include <sstream>
#include <ctype.h>
#include <iostream>

Model::Model(std::string config)
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    configure(config);
}

void Model::configure(std::string &info)
{
    for (char &i : info) i = toupper(i);

    int it = 0;
    std::string detail;
    std::istringstream ss(info);

    char typeLeft, positionLeft, ringLeft;
    char typeMid, positionMid, ringMid;
    char typeRight, positionRight, ringRight;

    while (getline(ss, detail, '/')) {
        if (it == 0) {
            typeLeft = detail.at(0);
            typeMid = detail.at(1);
            typeRight = detail.at(2);
        } else if (it == 1) {
            positionLeft = detail.at(0);
            positionMid = detail.at(1);
            positionRight = detail.at(2);
        } else if (it == 2) {
            ringLeft = detail.at(0);
            ringMid = detail.at(1);
            ringRight = detail.at(2);

            _rotorLeft.set(typeLeft, positionLeft, ringLeft);
            _rotorMid.set(typeMid, positionMid, ringMid);
            _rotorRight.set(typeRight, positionRight, ringRight);

        } else if (it == 3) {
            _reflector.set(detail.at(0));

        } else if (it == 4) {
            std::vector<std::pair<char, char>> plugPairs;
            std::string pair;
            std::istringstream pairSS(detail);

            while (getline(pairSS, pair, '.')) {
                plugPairs.emplace_back(pair.at(0), pair.at(1));
                plugPairs.emplace_back(pair.at(1), pair.at(0));
            }
            _plugboard.set(plugPairs);
        }

        ++it;
    }

}

void Model::steppingMechanism()
{
    _rotorRight.turn();
    if (_rotorRight.getStep().first) {
        _rotorMid.turn();
    } else if (_rotorMid.getStep().second) {
        _rotorMid.turn();
        _rotorLeft.turn();
    }
}

std::string Model::encrypt(std::string &message)
{
    for (char &i : message) i = toupper(i);

    _plugboard.transcript(message);

    for (char &i : message) {

        steppingMechanism();

        int index = _alphabet.find(i);
        int stage1 = _rotorRight.process(index, forward);
        int stage2 = _rotorMid.process(stage1, forward);
        int stage3 = _rotorLeft.process(stage2, forward);
        int stage4 = _reflector.reverse(stage3);
        int stage5 = _rotorLeft.process(stage4, backward);
        int stage6 = _rotorMid.process(stage5, backward);
        int stage7 = _rotorRight.process(stage6, backward);

        i = _alphabet.at(stage7);
    }

    _plugboard.transcript(message);

    return message;
}