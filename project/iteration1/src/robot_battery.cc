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
    double distance = sqrt (((x_distance)*(x_distance)) - ((y_distance)*(y_distance)));
    std::cout << "x old :" << old_pos.x() << std::endl;
    std::cout << "x new :" << new_pos.x() << std::endl;
    std::cout << "y old :" << old_pos.y() << std::endl;
    std::cout << "y new :" << new_pos.y() << std::endl;
    std::cout << "distance :" << distance << std::endl;
    charge_ = charge_ - kBASE_DEPLETION - (kLINEAR_SCALE_FACTOR * (distance/dt));
     std::cout << charge_ << std::endl;
     std::cout << dt << std::endl;
  /* @todo deplete battery by some value based on movement and speed */
  return charge_;
} /* deplete() */

void Accept(__unused const EventCollision * const e) {
  /* @todo deplete battery by some value -- arbitrary selected for bumping */
}

NAMESPACE_END(csci3081);
