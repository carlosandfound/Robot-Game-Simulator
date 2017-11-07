/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_battery.h"
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/*
 * The depletion of the battery is determined by taking the product of a
 * contant linear factor of 0.1 and speed of the robot (calculated by dividing
 * distance over time). This product is then subtracted from the current
 * battery level to get the new charge.
 */
double RobotBattery::Deplete(Position old_pos, Position new_pos, double dt) {
    int x_distance = (new_pos.x() - old_pos.x());
    int y_distance = (new_pos.y() - old_pos.y());
    double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
    double new_Charge = charge_ - (kLINEAR_SCALE_FACTOR * (distance/dt));

    if ((new_pos.x() != old_pos.x()) || (new_pos.y() != old_pos.y())) {
      if (new_Charge < 0) {
        charge_ = 0;
      } else {
        charge_ = new_Charge;
      }
    }
  return charge_;
} /* deplete() */

void RobotBattery::Accept(__unused const EventCollision * const e) {
  double new_Charge = charge_ - 5;
  if (new_Charge <= 0) {
    charge_ = 0;
  } else {
    charge_ = new_Charge;
  }
}

NAMESPACE_END(csci3081);
