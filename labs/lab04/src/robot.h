#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Robot {
private:
    double size = 0.0;
    std::string color = "";
    double x_pos = 0.0;
    double y_pos = 0.0;
    double velocity = 0.0;

public:
  void set_size(double t);
  double get_size();
  void set_color(std::string t);
  std::string get_color();
  void set_x_pos(double t);
  double get_x_pos();
  void set_y_pos(double t);
  double get_y_pos();
  void set_velocity(double t);
  double get_velocity();
  
};

#endif  // SRC_ROBOT_H_
