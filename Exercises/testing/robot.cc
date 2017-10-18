#include <math.h>
#include "robot.h"


Robot::Robot() : radius(5), position(0,0) {
}

Robot::Robot(int r, int x, int y) : radius(r), position(x,y) {
}

bool Robot::CheckOverlap(const Robot& robot2){
  // Get distance between centers
  int deltaX = robot2.get_position().x - this->get_position().x;
  int deltaY = robot2.get_position().y - this->get_position().y;

  int distance = sqrt((double)((deltaX*deltaX) + (deltaY*deltaY)));

  // check overlap
  if (distance < this->get_radius() + robot2.get_radius()) {
    return true;
  }
  return false;
}
