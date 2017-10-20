#include <iostream>
#include <string>

#include "tests.h"

void ExpectEqual(std::string test, int expect, int got) {
  std::cout << test << ":";
  if (expect != got) {
    printf("FAIL: expected %d, returned %d\n", expect, got);
  } else {
    printf("PASS\n");
  }
}

void ExpectEqual(std::string test, float expect, float got) {
  std::cout << test << ":";
  if (expect != got) {
    printf("FAIL:: expected %f, returned %f\n", expect, got);
  } else {
    printf("PASS\n");
  }
}

void ExpectEqual(std::string test, bool expect, int got) {
  char * expect_string;
  char * got_string;
  if (expect) {
    expect_string = "True";
  } else {
    expect_string = "False";
  }
  if (got) {
    got_string = "True";
  } else {
    got_string = "False";
  }
  std::cout << test << ":";
  if (expect != got) {
    printf("FAIL: expected %s, returned %s\n",
      expect_string, got_string );
  } else {
    printf("PASS\n");
  }
}
