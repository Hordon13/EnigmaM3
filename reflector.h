#ifndef ENIGMAM3_REFLECTOR_H
#define ENIGMAM3_REFLECTOR_H

#include <string>

class Reflector {
public:
    Reflector();

    void set(const char &type);

    int reverse(int signal);
private:
    std::string _alphabet;
    std::string _wiring;
};


#endif