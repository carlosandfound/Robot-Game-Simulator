//
//  Duck.cpp
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#include "Duck.h"

#include <iostream>

using std::cout;
using std::endl;

Duck::Duck() {
    SetName("Duck");
}

Duck::Duck(std::string name) {
    SetName(name);
}

void Duck::PerformQuack() {
    printf("Quack\n");
}
