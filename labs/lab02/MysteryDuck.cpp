#include <iostream>
#include <string>
#include "MysteryDuck.h"

using std::cout;
using std::endl;
using std::string;

//MysteryDuck::MysteryDuck() : Duck() {
//}

MysteryDuck :: MysteryDuck(std::string inputDescription, std::string inputSound) {
  sound = inputSound;
  description = inputDescription;
}

string MysteryDuck::getDescription() {
    return description;
}

void MysteryDuck::performQuack() {
    cout << sound << endl;
}
