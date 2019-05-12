#ifndef ENIGMAM3_PLUGBOARD_H
#define ENIGMAM3_PLUGBOARD_H

#include <string>
#include <vector>
#include <map>

class Plugboard {
public:
    void set(std::vector<std::pair<char, char>> plugPairs);

    void transcript(std::string &message);
private:
    std::map<char, char> _plugboard;
};


#endif