/**
 * @file player.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_PLAYER_H_
#define PROJECT_ITERATION3_SRC_PLAYER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/motion_handler_player.h"
#include "src/robot_motion_behavior.h"
#include "src/sensor_touch.h"
#include "src/robot_battery.h"
#include "src/arena_mobile_entity.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
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
 * @brief Class representing a mobile player within the arena.
 *
 * players have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have a touch sensor for
 * responding to collision events which is activated/deactivated on collision
 * events.
 *
 * players can take command from the player through keypress. They also have
 * batteries that will get depleted as they move or collide with other
 * entities.
 */
class Player : public ArenaMobileEntity {
 public:
  /**
   * @brief Constructor.
   *
   * @param params A player_params passed down from main.cc for the
   * initialization of the player.
   */
  explicit Player(const struct robot_params *const params);

  /**
   * @brief Reset the player's battery to full after an encounter with the
   * RechargeStation.
   */
  void ResetBattery();

  /**
   * @brief Reset the player to a newly constructed state (needed for reset
   * button to work in GUI).
   */
  void Reset() override;

  /**
   * @brief Update the player's position and velocity after the specified
   * duration has passed.
   *
   * @param dt The # of timesteps that have elapsed since the last update.
   */
  void TimestepUpdate(unsigned int dt) override;

  /**
   * @brief Accept a recharge event.
   *
   * This causes the player's battery to become fully charged.
   *
   * @param e The recharge event.
   */
  void Accept(__unused const EventRecharge *const e);

  /**
   * @brief Pass along a collision event (from Arena) to the touch sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of information from different sources. The player's heading will be updated
   * to move it away from the incident angle at the point of contact.
   *
   * @param e The collision event.
   */
  void Accept(__unused const EventCollision *const e) override;

  /**
   * @brief Handle user input commands to change the player's heading or speed.
   *
   * @param e The command to process.
   */
  void Accept(__unused const EventCommand *const e);

  /**
   * @brief Getter method for the player's battery level.
   *
   * @return The current battery level of the player.
   */
  double get_battery_level() { return battery_.level(); }

  /**
   * @brief Getter method for the player's max battery level.
   *
   * @return The max battery level of the player.
   */
  double get_max_battery_level() { return battery_.max_level(); }

  /**
   * @brief Getter method for the player's heading angle.
   *
   * @return The current heading angle of the player.
   */
  double get_heading_angle() const override {
    return motion_handler_.heading_angle();
  }

  /**
   * @brief Setter method for the player's heading angle.
   *
   * @param ha The new heading angle of the player.
   */
  void set_heading_angle(double ha) override {
    motion_handler_.heading_angle(ha);
  }

  /**
   * @brief Getter method for the player's speed.
   *
   * @return The current speed of the player.
   */
  double get_speed() const override { return motion_handler_.get_speed(); }

  /**
   * @brief Setter method for the player's speed.
   *
   * @param sp The new speed of the player.
   */
  void set_speed(double sp) override { motion_handler_.set_speed(sp); }

  /**
   * @brief Get the name of the player for visualization purposes, and to
   * aid in debugging.
   *
   * @return Name of the player.
   */
  std::string get_name() const override {
    return "Player" + std::to_string(id_);
  }

  /**
   * @brief Getter method for the player's entity type id, which is 0
   */
  int get_entity_type_id() const override { return 0; }

  /**
   * @brief Getter method for the time at which the player should be unfrozen
   */
  int get_unfreeze_time() const { return unfreeze_time_; }

  /**
   * @brief Setter method for the time at which the player should be unfrozen
   */
  void set_unfreeze_time(int t) { unfreeze_time_ = t; }

  /**
   * @brief Getter method for player's frozen status in arena
   */
  bool get_frozen() const { return frozen_; }

  /**
   * @brief Setter method for player's frozen status
   */
  void set_frozen(bool s) { frozen_ = s; }

 private:
  static unsigned int next_id_;
  int unfreeze_time_;
  bool frozen_ = false;
  int id_;
  double heading_angle_;
  double angle_delta_;
  double speed_delta_;
  RobotBattery battery_;
  MotionHandlerPlayer motion_handler_;
  RobotMotionBehavior motion_behavior_;
  SensorTouch sensor_touch_;
  Position initial_pos_;  // initial position of the player, used by Reset()
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_PLAYER_H_
