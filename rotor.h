#ifndef ENIGMAM3_ROTOR_H
#define ENIGMAM3_ROTOR_H

#include <string>
#include <vector>

class Rotor {
public:
    Rotor();

    void set(const char &type, char &position, char &ring);

    void turn();

    int process(int signal);

private:
    std::string _ring;
    std::string _core;
    std::string _wiring;

    std::string _alphabet;
    std::pair<char, char> _notch1;
    std::pair<char, char> _notch2;
    bool _step;
    bool _stepDouble;
};


#endif
