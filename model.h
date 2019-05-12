#ifndef ENIGMAM3_MODEL_H
#define ENIGMAM3_MODEL_H

#include "rotor.h"
#include "reflector.h"
#include "plugboard.h"

class Model {
public:
    Model(std::string config = "368/234/AAA/B/AN.EZ.HK.IJ.LR.MQ.OT.PV.SW.UX");

    std::string encrypt(std::string &message);

private:
    Rotor _rotorLeft;
    Rotor _rotorMid;
    Rotor _rotorRight;
    Reflector _reflector;
    Plugboard _plugboard;

    std::string _alphabet;
    std::string _config;

    void configure(std::string &info);
};

#endif