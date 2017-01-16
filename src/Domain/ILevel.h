
#ifndef GRIMWALL_LEVEL_H
#define GRIMWALL_LEVEL_H

#include <string>

class ILevel {
protected:
    std::string name {""};
    std::string map {""};
    std::string next {""};
public:
    std::string getName();
    std::string getMap();
    std::string getNext();
};


#endif //GRIMWALL_LEVEL_H
