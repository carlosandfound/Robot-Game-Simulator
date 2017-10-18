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


