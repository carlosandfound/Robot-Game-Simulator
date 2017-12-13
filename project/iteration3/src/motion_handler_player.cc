/**
 * @file motion_handler_player.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/motion_handler_player.h"
#include "src/motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
MotionHandlerPlayer::MotionHandlerPlayer() :
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
void MotionHandlerPlayer::AcceptCommand(enum event_commands cmd) {
  switch (cmd) {
    case COM_TURN_LEFT:
      heading_angle(heading_angle() - angle_delta());
      if (heading_angle() < 0) {
        heading_angle(heading_angle() + max_angle());
      }
      break;
    case COM_TURN_RIGHT:
      heading_angle(heading_angle()+angle_delta());
      if (heading_angle() > max_angle()) {
        heading_angle(heading_angle() - max_angle());
      }
      break;
    case COM_SPEED_UP:
      set_speed(get_speed()+speed_delta());
      if (get_speed() > max_speed()) {
        set_speed(max_speed());
      }
      break;
    case COM_SLOW_DOWN:
      set_speed(get_speed() - speed_delta());
      if (get_speed() < 0) {
        set_speed(0);
      }
      break;
    default:
      std::cerr << "FATAL: bad actuator command" << std::endl;
      assert(false);
      break;
  } /* switch() */
} /* accept_command() */

void MotionHandlerPlayer::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    heading_angle(-st.angle_of_contact());
    st.Reset();
  }
}

NAMESPACE_END(csci3081);
