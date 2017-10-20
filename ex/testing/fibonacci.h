#ifndef TESTS_FIBONACCI_H_
#define TESTS_FIBONACCI_H_

int fibonacci(int n) {
  // Calculate the nth fibonacci number
  int sum_n;
  int sum_n2 = 1;
  int sum_n1 = 1;
  for (int i=0;i<n;i++) {
    sum_n = sum_n1 + sum_n2;
    sum_n1 = sum_n;
    sum_n2 = sum_n1;
  }
  return sum_n;
}
#endif
