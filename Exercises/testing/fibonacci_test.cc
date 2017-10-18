#include <iostream>

#include "fibonacci.h"
#include "tests.h"

void fibonacci_unittest() {

  // test negative
  ExpectEqual("Negative Input",fibonacci(-1),-1);

  // test 0
  ExpectEqual("0 Input",fibonacci(0),0);

  // test boundary
  ExpectEqual("Border 1",fibonacci(1),1);
  ExpectEqual("Border 2",fibonacci(2),2);

  // test typical
  ExpectEqual("Typical 5", fibonacci(5), 5);
  ExpectEqual("Typical 10", fibonacci(10), 55);
}
