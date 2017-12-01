/**
 * @file motion_handler_robot.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_MOTION_HANDLER_ROBOT_H_
#define PROJECT_ITERATION2_SRC_MOTION_HANDLER_ROBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot_params.h"
#include "src/motion_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class managing the Robot's speed and heading angle based on sensor
 * readings in wake of an event collision or proximity event.
 *
 * Currently, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class MotionHandlerRobot : public MotionHandler {
 public:
  /**
   * @brief Default constructor.
   */
  MotionHandlerRobot();

  /**
  * @brief Update the speed and the heading angle according to the reading of
  * the sensor touch based on collision data.
  *
  * @param st A SensorTouch to be read.
  */
  void UpdateVelocity(SensorTouch st) override;

  /**
  * @brief Update the speed and the heading angle according to the reading of
  * the proximity sensor based on proximity data.
  *
  * @param st A SensorTouch to be read
  * @param superbot A bool determining whether or not robot is superbot
  */
  void UpdateVelocity(SensorProximity * sp, bool superbot_);

  /**
  @brief Update the speed and the heading angle according to the reading of
  * the distress sensor based on the distress event data.
  *
  * @param st A SensorTouch to be read.
  * @param superbot A bool determining whether or not robot is superbot
  */
  void UpdateVelocity(SensorDistress * sd, bool superbot_);

  /**
  @brief reset the motion handler to its original state
   */
  void Reset() override;

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
  double max_angle_;
  double speed_delta_;
  double angle_delta_;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION2_SRC_MOTION_HANDLER_ROBOT_H_
