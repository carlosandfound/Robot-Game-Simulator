#ifndef DUCKS_EXERCISES_FLY_H_
#define DUCKS_EXERCISES_FLY_H_

#include <iostream>
#include <stdlib.h>

//-----------------------------------------------
//   FLYING

#define MPH_DEFAULT 5

using namespace std;

class FlyBehavior {
protected:
  double milesPerHour;
public:
  FlyBehavior();
  virtual void fly();
  virtual double getSpeed();
};

class FlyWithWings : public FlyBehavior {
public:
  FlyWithWings();
  virtual void fly();
};

class NoFly : public FlyBehavior {
public:
  // cannot fly <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Fill this in;
};

class FlyWithRocket : public FlyBehavior {
  // Can fly REALLY fast - don't use the default speed <<<<<<<<<< Fill this in;
};

#endif
