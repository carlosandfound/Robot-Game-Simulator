/**
 * @file motion_handler.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_
#define PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_commands.h"
#include "src/arena_mobile_entity.h"
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief base class of for various tyes of entities in the environment.
 *
 * Currently, both wheels can't be controlled independently.
 */
class MotionHandler {
 public:
  /**
   * @brief Default constructor.
   */
  // MotionHandler();

  virtual ~MotionHandler() = default;

  /**
   * @brief Reset the actuators to their newly constructed/un-commanded state.
   *
   * Currently does nothing.
   */
  virtual void Reset() {}

  /**
  * @brief Update the speed and the heading angle according to the sensor
  * readings.
  *
  * Currently does not change speed.
  *
  * @param st A SensorTouch to be read.
  */
  virtual void UpdateVelocity(SensorTouch st) = 0;

  /**
   * @brief Getter method for speed.
   *
   * @return The current speed.
   */
  virtual double get_speed() const = 0;

  /**
   * @brief Setter method for speed.
   *
   * @param sp The new speed.
   */
  virtual void set_speed(double sp) = 0;

  /**
   * @brief Getter method for heading angle.
   *
   * @return The current heading angle.
   */
  virtual double heading_angle() const = 0;

  /**
   * @brief Setter method for heading angle.
   *
   * @param ha The new heading angle.
   */
  virtual void heading_angle(double ha) = 0;

  /**
   * @brief Getter method for the maximum speed.
   *
   * @return The current maximum speed.
   */
  virtual double max_speed() const = 0;

  /**
   * @brief Setter method for the maximum speed.
   *
   * @param ms The new maximum speed.
   */
  virtual void max_speed(double ms) = 0;

  /**
   * @brief Getter method for the maximum angle.
   *
   * @return The current maximum angle.
   */
  virtual double max_angle() const = 0;

  /**
   * @brief Setter method for the maximum angle.
   *
   * @param ma The new maximum angle.
   */
  virtual void max_angle(double ma) = 0;

  /**
   * @brief Getter method for the speed delta.
   *
   * @return The current speed delta.
   */
  virtual double speed_delta() const = 0;

  /**
   * @brief Setter method for the speed delta.
   *
   * @param sd The new speed delta.
   */
  virtual void speed_delta(double sd) = 0;

  /**
   * @brief Getter method for the angle delta.
   *
   * @return The current angle delta.
   */
  virtual double angle_delta() const = 0;

  /**
   * @brief Setter method for the angle delta.
   *
   * @param ad The new angle delta.
   */
  virtual void angle_delta(double ad) = 0;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_
