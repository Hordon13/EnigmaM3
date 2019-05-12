#ifndef ENIGMAM3_ROTOR_H
#define ENIGMAM3_ROTOR_H

#include <string>
#include <vector>

class Rotor {
public:
    Rotor();

    void setRotor(const std::string&, const std::string&, const std::string&);

    void turn();

    int process(int signal);

private:
    std::vector<char> _ring;
    std::vector<char> _core;
    std::string _wiring;

    std::string _alphabet;
    int _notch1;
    int _notch2;

    std::string _typeI;
    std::string _typeII;
    std::string _typeIII;
    std::string _typeIV;
    std::string _typeV;
    std::string _typeVI;
    std::string _typeVII;
    std::string _typeVIII;
};


#endif
