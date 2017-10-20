/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "motion_handler.h"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandler::MotionHandler() :
    heading_angle_(0), speed_(0), max_speed_(5) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionHandler::UpdateVelocity(bool collided) {
  if (collided) {
    heading_angle_ = -heading_angle_;
  }
}
