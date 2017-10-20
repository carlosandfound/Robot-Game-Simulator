#include <iostream>
#include <stdlib.h>

#define MPH_DEFAULT 5
#define DB_DEFAULT 10

using namespace std;

//-----------------------------------------------
//   QUACKING

class QuackBehavior {
protected:
  double volume;
public:
  QuackBehavior() : volume(DB_DEFAULT) {}
  void quack() { cout << "Generic Quack at " << volume << " decibels" << endl; }
};

class Quack : public QuackBehavior {
public:
  Quack() {}
  void quack() { cout << "Quack at " << volume << " decibels" << endl; }
};

class Mute : public QuackBehavior {
public:
  Mute() { volume = 0; }
  void quack() { cout << "Cannot talk." << endl; }
};

class Squeak : public QuackBehavior {
public:
  Squeak() {}
  Squeak(int d) { volume = d; }
  void quack() { cout << "Squeak at " << volume << " decibels." << endl; }
};

class Honk : public QuackBehavior {
  // This is a confused swan that honks instead of quacks. Fill this in. <<<<<<<<<<<<<<<<
};


//-----------------------------------------------
//   FLYING

class FlyBehavior {
protected:
  double milesPerHour;
public:
  FlyBehavior() : milesPerHour(MPH_DEFAULT) {}
  void fly() { cout << "Generic Flying at " << milesPerHour << " mph." << endl; }
};
  
class FlyWithWings : public FlyBehavior {
public:
  FlyWithWings() {}
  void fly() { cout << "Fly at speed of " << milesPerHour << " mph." << endl; }
};

class NoFly : public FlyBehavior {
public:
  // cannot fly <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Fill this in;
};

class FlyWithRocket : public FlyBehavior {
  // Can fly REALLY fast - don't use the default speed <<<<<<<<<< Fill this in;
};

//----------------------------------------------
//  THE DUCKS

class Duck {
protected:
  FlyBehavior flyBehavior;
  QuackBehavior quackBehavior;
public:
  Duck() {
    flyBehavior = FlyWithWings();
    quackBehavior = Quack();
  }
  void display() { cout << "I am a duck." << endl; }
  void fly() { flyBehavior.fly(); }
  void quack() { quackBehavior.quack(); }
};

class Mallard : public Duck {
public:
  Mallard() {
    flyBehavior = FlyWithWings();
    quackBehavior = Quack();
  }
  void display() { cout << "I am a Mallard." << endl; }
  void quack() { quackBehavior.quack(); }
  void fly() { flyBehavior.fly(); }
};

class RubberDuck : public Duck {
public:
  RubberDuck() { 
    flyBehavior = NoFly();
    quackBehavior = Squeak(2);
  }
  void display() { cout << "I am a Rubber Duck." << endl; }
  void quack() { quackBehavior.quack(); }
  void fly() { flyBehavior.fly(); }
};

int main() {

  Mallard mary;
  RubberDuck ralph;
  Duck donald;

  cout << endl << "Donald does this ... " << endl;
  donald.display();
  donald.fly();
  donald.quack();

  cout << endl << "Mary does this ... " << endl;
  mary.display();
  mary.fly();
  mary.quack();
  
  cout << endl << "Ralph does this ... " << endl;
  ralph.display();
  ralph.fly();
  ralph.quack();

  cout << endl;
}


