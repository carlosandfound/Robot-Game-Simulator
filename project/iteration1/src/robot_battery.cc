/**
 * @file robot_battery.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include "src/robot_battery.h"
#include <iostream>
#include <math.h>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
double RobotBattery::Deplete(Position old_pos, Position new_pos, double dt) {
    int x_distance = (new_pos.x() - old_pos.x());
    int y_distance = (new_pos.y() - old_pos.y());
    double distance = sqrt ((pow (x_distance,2)) + (pow (y_distance,2)));
    double new_Charge = charge_ - (kLINEAR_SCALE_FACTOR * (distance/dt));

    if ((new_pos.x() != old_pos.x()) || (new_pos.y() != old_pos.y())) {
      if (new_Charge < 0) {
        charge_ = 0;
      }
      else {
        charge_ = new_Charge;
      }
    }
    /*
    std::cout << "x old :" << old_pos.x() << std::endl;
    std::cout << "x new :" << new_pos.x() << std::endl;
    std::cout << "y old :" << old_pos.y() << std::endl;
    std::cout << "y new :" << new_pos.y() << std::endl;
    std::cout << "distance :" << distance << std::endl;
    std::cout << "charge before : " << charge_ << std::endl;
    charge_ = charge_ - (kLINEAR_SCALE_FACTOR * (distance/dt));
    std::cout << "charge after : " << charge_ << std::endl;
    std::cout << dt << std::endl;
    */
  /* @todo deplete battery by some value based on movement and speed */
  return charge_;
} /* deplete() */

void Accept(__unused const EventCollision * const e) {
  /* @todo deplete battery by some value -- arbitrary selected for bumping */
}

NAMESPACE_END(csci3081);
