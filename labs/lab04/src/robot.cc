/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"

/*******************************************************************************
 * Member fucntions
 ******************************************************************************/

Robot::void set_size(double t) {
    size = t;
  }

Robot::double get_size(void) {
    return size;
  }

Robot::void set_color(std::string t) {
    size = t;
  }

Robot::string get_color(void) {
    return color;
  }

Robot::void set_x_pos(double t) {
    x_pos = t;
  }

Robot::double get_x_pos(void) {
    return x_pos;
  }

Robot::void set_y_pos(double t) {
    y_pos = t;
  }

Robot::double get_y_pos(void) {
    return y_pos;
  }

Robot::void set_velocity(double t) {
    velocity = t;
  }

Robot::double get_velocity(void) {
    return velocity;
  }
};
