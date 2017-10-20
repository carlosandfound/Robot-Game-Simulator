/**
 * @file actuator_handler.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_MOTION_HANDLER_H_
#define SRC_ROBOT_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "mobile_entity.h"

class MotionHandler {
 public:
  MotionHandler();

  /**
  * @brief Change the speed and direction according to the sensor readings.
  *
  * @param touch sensor that can be activated and contains point-of-contact.
  *
  */
  void UpdateVelocity(bool collided);

  double speed(void) const { return speed_; }
  void speed(double sp) { speed_ = sp; }

  double heading_angle(void) const { return heading_angle_;}
  void heading_angle(double ha) { heading_angle_ = ha; }

  double max_speed(void) const { return max_speed_; }
  void max_speed(double ms) { max_speed_ = ms; }

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
};

#endif /* SRC_ROBOT_MOTION_HANDLER_H_ */
