#ifndef TESTS_TESTS_H_
#define TESTS_TESTS_H_

#include <string>

// These are my "homegrown" version of Google test asserts
void ExpectEqual(std::string test, int expect, int got);
void ExpectEqual(std::string test, float expect, float got);
void ExpectEqual(std::string test, bool expect, int got);

#endif
