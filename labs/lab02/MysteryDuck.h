
#ifndef LAB02_MYSTERYDUCK_H_
#define LAB02_MYSTERYDUCK_H_

#include <string>
#include "Duck.h"

class MysteryDuck : public Duck {

private:
    std::string sound;
    std::string description;

public:
    MysteryDuck(std::string inputDescription, std::string inputSound);
    std::string getDescription();
    void performQuack();
};

#endif
