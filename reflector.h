#ifndef ENIGMAM3_REFLECTOR_H
#define ENIGMAM3_REFLECTOR_H

#include <string>

class Reflector {
public:
    void set(const std::string &type);

    int reverse(int signal);
private:
    std::string _wiring;
};


#endif