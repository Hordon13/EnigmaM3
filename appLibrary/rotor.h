#ifndef ENIGMAM3_ROTOR_H
#define ENIGMAM3_ROTOR_H

#include <string>
#include <vector>

enum Direction {
    forward,
    backward
};

class Rotor {
public:
    Rotor();

    void set(const char &type, char &position, char &ring);

    void turn();

    int process(int signal, Direction direction);

    const std::pair<bool, bool> &getStep() const;

    const std::string &getRing() const;

private:
    std::string _ring;
    std::string _core;
    std::string _wiring;

    std::pair<char, char> _notch1;
    std::pair<char, char> _notch2;
    std::pair<bool, bool> _step;
};

#endif
