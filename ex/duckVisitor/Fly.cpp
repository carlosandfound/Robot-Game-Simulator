#include <iostream>
#include <stdlib.h>

#include "Fly.h"

//-----------------------------------------------
//   FLYING BEHAVIOR

using namespace std;

FlyBehavior::FlyBehavior() {
  milesPerHour = MPH_DEFAULT;
}

void FlyBehavior::fly() {
  cout << "Generic Flying at " << milesPerHour << " mph." << endl;
}

double FlyBehavior::getSpeed() {
  return milesPerHour; }

//-----------------------------------------------
//   FLY WITH WINGS

FlyWithWings::FlyWithWings() {
}

void FlyWithWings::fly() {
  cout << "Fly with wings at speed of " << milesPerHour << " mph." << endl;
}

//-----------------------------------------------
//   NO FLYING

//NoFly::NoFly() {}

//-----------------------------------------------
//   FLY WITH ROCKET

//FlyWithRocket::FlyWithRocket() {}
