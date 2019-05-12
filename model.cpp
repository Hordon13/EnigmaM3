#include <sstream>
#include "model.h"

Model::Model(const std::string &config)
{
    _alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    _config = config;
    configure(config);

}

void Model::configure(std::string info)
{
    for (char &i : info) i = toupper(i);

    int it = 0;
    std::string detail;
    std::istringstream ss(info);

    std::string typeLeft, positionLeft, ringLeft;
    std::string typeMid, positionMid, ringMid;
    std::string typeRight, positionRight, ringRight;

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
            _reflector.set(detail);

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

std::string Model::encrypt(std::string &message)
{
    return "*****";
}