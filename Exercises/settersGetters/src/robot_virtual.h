/**
 * @file robot.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_VIRTUAL_H_
#define SRC_ROBOT_VIRTUAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>

#include "mobile_entity_virtual.h"
#include "motion_behavior.h"
#include "motion_handler.h"


/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile robot within the arena.
 *
 * Robots have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 */
class RobotVirtual : public MobileEntityVirtual {
 public:
  explicit RobotVirtual(const Position& pos, const int rad );

  /**
  * @brief Setter and Getter for position.
  */
  void set_position(const Position& pos) { position_ = pos; }
  const Position& get_position(void) const { return position_; }

  /**
  * @brief Setter and Getter for radius.
  */
  void set_radius(const int& rad) { radius_ = rad; }
  const int& get_radius(void) const { return radius_; }

  /**
   * @brief Update the robot's position and velocity after the specified
   * duration has passed.
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
