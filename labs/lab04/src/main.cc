/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_viewer.h"
#include "robot.h"

using std::cout;
using std::endl;

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char **argv) {
  //csci3081::InitGraphics();

  // RobotViewer is a subclass of GraphicsApp, found in libSimpleGraphics
  // Run() is a function defined in the GraphicsApp class definition.
  // Run() calls nanogui::mainloop().

  /*
  csci3081::RobotViewer *app = new csci3081::RobotViewer();
  app->Run();
  csci3081::ShutdownGraphics();

  */
  Robot robot;
  robot.set_size(1.0);
  robot.set_color("red");
  robot.set_x_pos(5.0);
  robot.set_y_pos(-5.0);
  robot.set_velocity(3.14);
  cout << "Size: " << robot.get_size() << " Color: " << robot.get_color() << " X-coor: " <<
    robot.get_x_pos() << " Y-coor: " << robot.get_y_pos() << " Velocity: " << robot.get_velocity() << endl;
  return 0;
}
