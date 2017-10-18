/**
 * @file robot_motion_behavior.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <math.h>
#include "motion_behavior.h"
#include "position.h"

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionBehavior::UpdatePosition(MobileEntity * const ent) {

  Position new_pos;

  // Movement is always along the heading_angle (i.e. the hypotenuse)
  new_pos.x +=  cos(ent->heading_angle()*3.14/180.0)*ent->get_speed()*1;
  new_pos.y += sin(ent->heading_angle()*3.14/180.0)*ent->get_speed()*1;
  ent->set_position(new_pos);
} /* update_position() */

void MotionBehavior::UpdatePosition(
  MobileEntityVirtual * const ent) {

  Position new_pos;
  
  // Movement is always along the heading_angle (i.e. the hypotenuse)
  new_pos.x += cos(ent->heading_angle()*3.14/180.0)*ent->get_speed()*1;
  new_pos.y += sin(ent->heading_angle()*3.14/180.0)*ent->get_speed()*1;
  ent->set_position(new_pos);
} /* update_position() */
