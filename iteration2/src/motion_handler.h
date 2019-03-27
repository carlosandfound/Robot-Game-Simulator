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
#include "src/sensor_proximity.h"
#include "src/sensor_distress.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief base class of for various tyes of motion handlers that controlled
 * the motion of mobile entities. The Robot, HomeBase and Player motion handlers
 * all inherit from this base class.
 *
 * As this is a base class, most of its methods are `virtual`.
 */
class MotionHandler {
 public:
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
  double get_speed() const { return speed_; }

   /**
    * @brief Setter method for speed.
    *
    * @param sp The new speed.
    */
  void set_speed(double sp) { speed_ = sp; }

   /**
    * @brief Getter method for heading angle.
    *
    * @return The current heading angle.
    */
  double heading_angle() const { return heading_angle_; }

   /**
    * @brief Setter method for heading angle.
    *
    * @param ha The new heading angle.
    */
  void heading_angle(double ha) { heading_angle_ = ha; }

   /**
    * @brief Getter method for the maximum speed.
    *
    * @return The current maximum speed.
    */
  double max_speed() const { return max_speed_; }

   /**
    * @brief Setter method for the maximum speed.
    *
    * @param ms The new maximum speed.
    */
  void max_speed(double ms) { max_speed_ = ms; }

   /**
    * @brief Getter method for the maximum angle.
    *
    * @return The current maximum angle.
    */
  double max_angle() const { return max_angle_; }

   /**
    * @brief Setter method for the maximum angle.
    *
    * @param ma The new maximum angle.
    */
  void max_angle(double ma) { max_angle_ = ma; }

   /**
    * @brief Getter method for the speed delta.
    *
    * @return The current speed delta.
    */
  double speed_delta() const { return speed_delta_; }

   /**
    * @brief Setter method for the speed delta.
    *
    * @param sd The new speed delta.
    */
  void speed_delta(double sd) { speed_delta_ = sd; }

   /**
    * @brief Getter method for the angle delta.
    *
    * @return The current angle delta.
    */
  double angle_delta() const { return angle_delta_; }

   /**
    * @brief Setter method for the angle delta.
    *
    * @param ad The new angle delta.
    */
  void angle_delta(double ad) { angle_delta_ = ad; }

 private:
  double heading_angle_ = 0;
  double speed_ = 0;
  double max_speed_ = 100;
  double max_angle_ = 360;
  double speed_delta_ = 30;
  double angle_delta_ = 30;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION2_SRC_MOTION_HANDLER_H_
