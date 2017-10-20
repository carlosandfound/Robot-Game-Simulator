#include <iostream>
#include <stdlib.h>
#include "Visitor.h"
#include "Fly.h"
#include "Quack.h"

#include "Duck.h"

using namespace std;

//----------------------------------------------
//  THE DUCKS

Duck::Duck() {
    flyBehavior = new FlyBehavior;
    quackBehavior = new QuackBehavior;
    name = "mystery";
}

void Duck::accept( Visitor * v ) { v->visit(this); }

void Duck::display() { cout << "I am a duck." << endl; }
void Duck::fly() { flyBehavior->fly(); }
void Duck::quack() { quackBehavior->quack(); }

double Duck::getSpeed() { return flyBehavior->getSpeed(); }
double Duck::getDB() { return quackBehavior->getDB(); }

void Duck::setName(string inName) { name = inName; }
string Duck::getName() { return name; }

//----------------------------------------------
//  MALLARD

Mallard::Mallard() {
  flyBehavior = new FlyWithWings;
  quackBehavior = new Quack;
}

void Mallard::accept( Visitor * v) { v->visit(this); }
void Mallard::display() { cout << "I am a Mallard." << endl; }

//----------------------------------------------
//  THE RUBBERDUCK

RubberDuck::RubberDuck() {
    flyBehavior = new NoFly;
    quackBehavior = new Squeak(2);
}

void RubberDuck::accept( Visitor * v) { v->visit(this); }

void RubberDuck::display() { cout << "I am a Rubber Duck." << endl; }
