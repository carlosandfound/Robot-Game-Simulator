#include "duck.h"

class ArrayPointerTest {
public:
  ArrayPointerTest(int size=3);
  ~ArrayPointerTest();
  void DisplayContents();

private:
  Duck ducks1_[3];
  Duck * ducks2_;
  Duck * ducks3_[3];
  Duck ** ducks4_;
  int size_;
};
