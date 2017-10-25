/**
 * @file robot_motion_handler.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
RobotMotionHandler::RobotMotionHandler() :
    heading_angle_(0),
  speed_(0),
  max_speed_(10) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
 void RobotMotionHandler::AcceptCommand(enum event_commands cmd) {
   //change speed/angle accordingly for each of the 4 commands
   // angle will be changed by delta 10
   switch (cmd) {
   case COM_TURN_LEFT:
     heading_angle_ = heading_angle_ - 10;
     break;
   case COM_TURN_RIGHT:
     heading_angle_ = heading_angle_ + 10;
     break;
   case COM_SPEED_UP:
     if (speed_ < max_speed_) {
       // max speed is 10...increase speed by 1
       speed_ = speed_ + 1;
     }
     break;
   case COM_SLOW_DOWN:
     if (speed_ > 0) {
       speed_ = speed_ - 1;
     }
     break;
   default:
     std::cerr << "FATAL: bad actuator command" << std::endl;
     //assert(0);
   } /* switch() */
 } /* accept_command() */

void RobotMotionHandler::UpdateVelocity(SensorTouch st) {
  if (st.activated()) {
    //std::cerr << "heading " << heading_angle_ << std::endl;
    //std::cerr << "angle " << st.angle_of_contact() << std::endl;
    heading_angle_ = -st.angle_of_contact();
  }
}

NAMESPACE_END(csci3081);
