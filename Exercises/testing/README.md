## Homegrown Testing Framework

### Fibonacci  

1. Look at "tests.cc" to see the assert statement options.
2. Look at "fibonacci_test.cc" to see how these assert statements are used.
3. _make_ and run the unittests `./unittests` to see how successful these tests were in finding errors!
4. No need to fix these errors. The point is to understand how test cases are created and used to develop a suite of tests.

### Robot

1. Look at "robot.h" and robot.cc".
2. In the file "robot_test.cc" notice there are no tests written. Remedy this by writing a test that tests the DEFAULT constructor. This would be composed of the instantiation of a robot, then a series of the provided assert statements (e.g. _ExpectEqual()_) to check that the values for the radius and the position are as expected. The tests in "fibonacci_test.cc" provide a guide on how to create these.
3. Write a test for the other constructor.
4. Look at _Robot::CheckOverlap()_. Identify some scenarios that would be good to test.
5. For each scenario, write a collection of assert statements to confirm the results.
