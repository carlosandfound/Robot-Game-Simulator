#include "robot.h"
#include <iostream>

using std::cout;

int main() {

  //      Robot rosyRobot(0,0,0);


  //rosyRobot.xyPosition(0,0);
  //rosyRobot.radianDirectionAngle(0);

  //      rosyRobot.display();


  /*
  c3poRobot.display();
  Robot c3poRobot(100,100);

  halRobot.display();
  Robot halRobot(3.14);

  Robot eveRobot(-100,-100,-3.14/4);
  eveRobot.display();
  */

  Robot rosyRobot;
  Robot c3poRobot(100,100);
  Robot halRobot(3.14);
  Robot eveRobot(-100,-100,-3.14/4);
  rosyRobot.display();
  c3poRobot.display();
  halRobot.display();
  eveRobot.display();
}
