#ifndef DUCKS_EXERCISES_QUACK_H_
#define DUCKS_EXERCISES_QUACK_H_

#include <iostream>
#include <stdlib.h>

//-----------------------------------------------
//   QUACKING

#define DB_DEFAULT 10

using namespace std;

class QuackBehavior {
protected:
  double volume;
public:
  QuackBehavior();
  virtual void quack();
  virtual double getDB();
};

class Quack : public QuackBehavior {
public:
  Quack();
  void quack();
};

class Mute : public QuackBehavior {
public:
  Mute();
  void quack();
};

class Squeak : public QuackBehavior {
public:
  Squeak();
  Squeak(int d);
  void quack();
};

class Honk : public QuackBehavior {
  // This is a confused swan that honks instead of quacks. Fill this in. <<<<<<<<<<<<<<<<
};

#endif
