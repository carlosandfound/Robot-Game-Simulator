//
//  main.cpp
//  CSCI3081-Lab1
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include <iostream>
#include "MallardDuck.h"
#include "RubberDuck.h"
#include "DecoyDuck.h"
#include "MysteryDuck.h"

using std::cout;
using std::endl;

int main() {

    // Create Ducks
    Duck jane;
    MallardDuck maloy;
    RubberDuck lemon;
    DecoyDuck decoy;

    cout << endl;

    // Introduce a generic duck
    cout << "This" << " is " << jane.getDescription() << " who says ";
    jane.performQuack();
    cout << endl;

    // Introduce a mallard duck
    cout << "This" << " is " << maloy.getDescription() << " who says " ;
    maloy.performQuack();
    cout << endl;

    // Introduce a rubber duck
    cout << "This" << " is " << lemon.getDescription() << " who says " ;
    lemon.performQuack();
    cout << endl;

    // Introduce a decoy duck
    cout << "This" << " is " << decoy.getDescription() << " who says ";
    decoy.performQuack();
    cout << endl;

    // Prompt user to enter description and sound of mystery duck
    std::string sound;
    std::string description;
    std::cout << "Enter duck description: ";
    std::getline(std::cin, description);
    std::cout << "Enter duck sound: ";
    std::getline(std::cin, sound);
    MysteryDuck who(description,sound);
    cout << endl;

    // Introduce a mystery duck
    cout << "This" << " is " << who.getDescription() << " who says ";
    who.performQuack();
    cout << endl;


    // I had to type the same thing over and over.
    // I think I can do better by wrapping it in a loop!
    // BUT WAIT, look at the output - it doesn't work! More on this later ...
    Duck ducks[3];
    ducks[0] = jane;
    ducks[1] = maloy;
    ducks[2] = lemon;
    //ducks[3] = decoy;;
    for (int i=0;i<3;i++) {
      cout << "This is " << ducks[0].getDescription() << " who says ";
      ducks[0].performQuack();
    }
    cout << endl;

    return 0;
}
