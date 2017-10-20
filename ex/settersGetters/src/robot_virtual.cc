/**
 * @file robot.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "robot_virtual.h"
#include "motion_behavior.h"
#include "mobile_entity_virtual.h"


/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotVirtual::RobotVirtual(const Position& pos, const int rad) :
  MobileEntityVirtual(pos, rad),
  id_(-1),
  motion_handler_(),
  motion_behavior_() {
    motion_handler_.heading_angle(270);
    motion_handler_.speed(5);
}


/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void RobotVirtual::TimestepUpdate() {

  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(true);

  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this);
} /* TimestepUpdate() */
