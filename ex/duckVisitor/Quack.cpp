#include <iostream>
#include <stdlib.h>

//-----------------------------------------------
//   QUACKING BEHAVIOR

#include "Quack.h"

using namespace std;

QuackBehavior::QuackBehavior() : volume(DB_DEFAULT) {
}

void QuackBehavior::quack() {
  cout << "Generic Quack at " << volume << " decibels" << endl;
}

double QuackBehavior::getDB() {
  return volume;
}

//-----------------------------------------------
//   QUACK

Quack::Quack() {
  volume = DB_DEFAULT;
}

void Quack::quack() {
  cout << "Quack at " << volume << " decibels" << endl;
}

//-----------------------------------------------
//   MUTE

Mute::Mute() {
  volume = 0;
}

void Mute::quack() {
  cout << "Cannot talk." << endl;
}

//-----------------------------------------------
//   SQUEAK

Squeak::Squeak() {
}

Squeak::Squeak(int d) {
  volume = d;
}

void Squeak::quack() {
  cout << "Squeak at " << volume << " decibels." << endl;
}

//-----------------------------------------------
//   HONK
/*
Honk::Honk() {
  // This is a confused swan that honks instead of quacks. Fill this in. <<<<<<<<<<<<<<<<
};
*/
