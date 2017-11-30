/**
 * @file robot.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_ROBOT_H_
#define PROJECT_ITERATION2_SRC_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/motion_handler_robot.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_entity_type.h"
#include "src/sensor_distress.h"
#include "src/sensor_proximity.h"
#include "src/sensor_touch.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/event_proximity.h"
#include "src/event_distress_call.h"
#include "src/position.h"
#include "src/event_command.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile robot within the arena.
 *
 * Robots have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events. Robots have 2 left/right proximity sensors, a distress call sensor,
 * an entity type sensor, and a touch sensor.
 *
 * Robots can take command from the player through keypress. They also have
 * batteries that will get depleted as they move or collide with other
 * entities.
 */
class Robot : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A robot_params passed down from main.cc for the
   * initialization of the Robot.
   */
  explicit Robot(const struct robot_params *const params);

  /**
   * @brief Reset the Robot's battery to full after an encounter with the
   * RechargeStation.
   */
  void ResetBattery();

  /**
   * @brief Reset the Robot to a newly constructed state (needed for reset
   * button to work in GUI).
   */
  void Reset() override;

  /**
   * @brief Update the Robot's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  /**
   * @brief Accept a recharge event.
   *
   * This causes the robot's battery to become fully charged.
   *
   * @param e The recharge event.
   */
  void Accept(__unused const EventRecharge *const e);

  /**
   * @brief Pass along a collision event (from Arena) to the touch sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of information from different sources. The Robot's heading will be updated
   * to move it away from the incident angle at the point of contact.
   *
   * @param e The collision event.
   */
  void Accept(const EventCollision *const e) override;

  /**
   * @brief Pass along a proximity event (from Arena) to the proximity sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of information from different sources. The Robot's heading will be updated
   * to move it away from the incident angle at the point of detection.
   *
   * @param e The proximity event.
   */
  void Accept(const EventProximity *const e);

  /**
   * @brief Pass along a distress event (from Arena) to the distress sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of information from different sources. The Robot's will be frozen
   * and emit a sensor distress signal.
   *
   * @param e The distress event.
   */
  void Accept(const EventDistressCall *const e);

  /**
   * @brief Handle user input commands to change the Robot's heading or speed.
   *
   * @param e The command to process.
   */
  // void Accept(const EventCommand *const e);

  /**
   * @brief Getter method for the Robot's battery level.
   *
   * @return The current battery level of the Robot.
   */
  double get_battery_level() { return battery_.level(); }

  /**
   * @brief Getter method for the Robot's max battery level.
   *
   * @return The max battery level of the Robot.
   */
  double get_max_battery_level() { return battery_.max_level(); }

  /**
   * @brief Getter method for the Robot's heading angle.
   *
   * @return The current heading angle of the Robot.
   */
  double get_heading_angle() const override {
    return motion_handler_.heading_angle();
  }

  /**
   * @brief Setter method for the Robot's heading angle.
   *
   * @param ha The new heading angle of the Robot.
   */
  void set_heading_angle(double ha) override {
    motion_handler_.heading_angle(ha);
  }

  /**
   * @brief Getter method for the Robot's speed.
   *
   * @return The current speed of the Robot.
   */
  double get_speed() const override { return motion_handler_.get_speed(); }

  /**
   * @brief Setter method for the Robot's speed.
   *
   * @param sp The new speed of the Robot.
   */
  void set_speed(double sp) override { motion_handler_.set_speed(sp); }

  /**
   * @brief getter method for robot's entity type sensor
   */
  class SensorEntityType *get_entity_type_sensor_() {
    return entity_type_sensor_;
  }

  /**
   * @brief getter method for robot's distress sensor
   */
  class SensorDistress *get_distress_sensor() { return distress_sensor_; }

  /**
   * @brief getter method for robot's left proximity sensor
   */
  class SensorProximity *get_left_proximity_sensor() const {
    return left_proximity_sensor_;
  }

  /**
   * @brief getter method for robot's right proximity sensor
   */
  class SensorProximity *get_right_proximity_sensor() const {
    return right_proximity_sensor_;
  }

  /**
   * @brief Getter method for a robot's entity type id, which is 1
   */
  int get_entity_type_id() const override { return 1; }

  /**
   * @brief Get the name of the Robot for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the Robot.
   */
  std::string get_name() const override {
    return "Robot" + std::to_string(id_);
  }

  void Transform();

  bool is_superbot() const {return is_superbot_;}

 private:
  static unsigned int next_id_;

  int id_;
  double heading_angle_;
  double angle_delta_;
  double speed_delta_;
  RobotBattery battery_;
  MotionHandlerRobot motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  SensorEntityType * entity_type_sensor_;
  SensorDistress * distress_sensor_;
  SensorProximity * left_proximity_sensor_;
  SensorProximity * right_proximity_sensor_;
  Position initial_pos_;  // initial position of the Robot, used by Reset()
  bool is_superbot_ = false;
  const robot_params * saved_params = 0;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ROBOT_H_
