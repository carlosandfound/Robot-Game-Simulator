//
//  Duck.h
//
//  Created by Sarit Ghildayal on 1/24/15.
//  Copyright (c) 2015 Sarit Ghildayal. All rights reserved.
//

#ifndef DUCK_H_
#define DUCK_H_

#include <string>

class Duck {
public:
    // Constructors and Destructor
    Duck();
    Duck(std::string name);
    ~Duck() {printf("destroying duck\n");};
    // Mutators and Accessors
    void PerformQuack();
    std::string GetName() {return m_name_;}
    void SetName(std::string name ) {m_name_ = name;}
protected:
    std::string m_name_;
};

#endif
