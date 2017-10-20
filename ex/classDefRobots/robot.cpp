#include "robot.h"

#include <math.h>
#include <iostream>

using std::cout;
using std::endl;

Robot::Robot( int x, int y, float theta) {
  position[0] = x;
  position[1] = y;
  directionAngle = theta;
}

void Robot::moveForward(int distance) {
  position[0] = position[0] + distance*cos(directionAngle);
  position[1] = position[1] + distance*sin(directionAngle);
}

void Robot::display() {
  cout
  << "Pos [" << position[0] << " " << position[1] << "]. angle "
  << directionAngle << endl;
}

void Robot::xyPosition( int x, int y) {
  position[0] = x;
  position[1] = y;
}

int* Robot::xyPosition() {
  return position;
}

void Robot::radianDirectionAngle(float d) {
  directionAngle = d;

}
float Robot::radianDirectionAngle() {
  return directionAngle;
}
