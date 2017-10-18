#include <iostream>
#include <string>

using std::string;

class DuckClass {
 protected:
  string typeOf;
  string name;
 public:
  DuckClass() {
    typeOf = "duck";
    name = "noname";
  }
  void display() { std::cout << "I am " << name << ", and I am a " << typeOf << ".\n"; }
  void fly() { std::cout << "I fly.\n"; };
  void quack() { std::cout << "I quack.\n"; };
};

class NoFlyDuck : public DuckClass {
 public:
  NoFlyDuck( string n = "lame" ) {
    typeOf = "noFly";
    name = n;
  }
  void fly() { std::cout << "I cannot fly.\n"; }
};

class NoQuackDuck : public DuckClass {
 public:
  NoQuackDuck( string n = "quiet" ) {
    typeOf = "noQuack";
    name = n;
  }
  void quack() { std::cout << "I cannot quack.\n"; }
};
