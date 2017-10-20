/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "robot.h"
#include "motion_behavior.h"


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const Position& pos, const int rad ) :
  MobileEntity(pos, rad),
  id_(-1),
  motion_handler_(),
  motion_behavior_() {
    motion_handler_.heading_angle(270);
    motion_handler_.speed(5);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate() {

  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(true);

  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this);
} /* TimestepUpdate() */
