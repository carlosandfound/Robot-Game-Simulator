/**
 * @file motion_handler_robot.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_robot.h"
#include "src/motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandlerRobot::MotionHandlerRobot() :
    MotionHandler(),
    heading_angle_(0),
    speed_(0),
    max_speed_(100),
    max_angle_(360),
    speed_delta_(30),
    angle_delta_(30) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void MotionHandlerRobot::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle(-st.angle_of_contact());
    st.Reset();
  }
}

void MotionHandlerRobot::UpdateVelocity(SensorProximity * sp, bool superbot_) {
  /*
  robot's motion handler should only change heading angle of the robot if it's
  not a superbot or the proximity sensor is turned off.
  */
  if (superbot_) {
    sp->activated(false);
  } else {
    if (sp->activated()) {
      heading_angle(-sp->angle_of_detection());
      set_speed(get_speed()*0.9);  // decrease speed by 10% if detected
      sp->Reset();
    }
  }
}

void MotionHandlerRobot::UpdateVelocity(SensorDistress * sd, bool superbot) {
  /*
  robot's motion handler should only change the robot's speed angle if it's not
  a superbot or the proximity sensor is turned off.
  */
  if (superbot) {
    sd->output(0);
    set_speed(5);
  } else {
    if (sd->output() == 1) {
      set_speed(0);
    } else {
      set_speed(5);
    }
  }
}

void MotionHandlerRobot::Reset() {
  set_speed(5);
}

NAMESPACE_END(csci3081);
