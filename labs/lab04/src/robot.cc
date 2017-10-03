/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"
#include <iostream>
#include <string>

using std::string;
/*******************************************************************************
 * Member fucntions
 ****************************** ************************************************/

void Robot::set_size(double t) {
    size = t;
  }

double Robot::get_size() {
    return size;
  }

void Robot::set_color(std::string t) {
    color = t;
  }

std::string Robot::get_color() {
    return color;
  }

void Robot::set_x_pos(double t) {
    x_pos = t;
  }

double Robot::get_x_pos() {
    return x_pos;
  }

void Robot::set_y_pos(double t) {
    y_pos = t;
  }

double Robot::get_y_pos() {
    return y_pos;
  }

void Robot::set_velocity(double t) {
    velocity = t;
  }

double Robot::get_velocity() {
    return velocity;
  }
