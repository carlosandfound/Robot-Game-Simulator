#include "array_pointer_test.h"

void helper() {
  printf("initializing all my ducks\n");
  ArrayPointerTest allMyDucks(3);
  allMyDucks.DisplayContents();
  printf("about to delete all my ducks\n");
}

int main(void) {
  helper();
  return 0;
}
