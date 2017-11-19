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
    set_speed(get_speed() * 0.9);  // decrease speed 10% if collided
    st.Reset();
  }
}

NAMESPACE_END(csci3081);
