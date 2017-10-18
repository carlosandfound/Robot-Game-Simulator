/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "mobile_entity.h"
#include "motion_behavior.h"
#include "motion_handler.h"

class Robot : public MobileEntity {
 public:
  explicit Robot(const Position& pos, const int rad );


  /**
   * @brief Update the robot's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate();

  double heading_angle(void) const {
    return motion_handler_.heading_angle();
  }
  void heading_angle(double ha) { motion_handler_.heading_angle(ha); }
  double get_speed(void) const { return motion_handler_.speed(); }
  void set_speed(double sp) { motion_handler_.speed(sp); }

 private:
  int id_;
  MotionHandler motion_handler_;
  MotionBehavior motion_behavior_;
};

#endif /* SRC_ROBOT_H_ */
