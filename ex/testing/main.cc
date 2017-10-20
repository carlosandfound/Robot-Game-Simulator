#include <iostream>

#include "fibonacci_test.cc"
#include "robot_test.cc"

int main() {
  std::cout << std::endl ;
  std::cout << "FIBONACCI TESTS" << std::endl;
  fibonacci_unittest();

  std::cout << std::endl << std::endl;
  std::cout << "ROBOT TESTS" << std::endl;
  robot_unittest();
}
