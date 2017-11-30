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
 * @brief Class managing an ArenaMobileEntity's speed and heading angle based
 * on collisions and (in the case of Robot) user inputs.
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
  * @brief Update the speed and the heading angle according to the sensor
  * readings.
  *
  * @param st A SensorTouch to be read.
  */
  void UpdateVelocity(SensorTouch st) override;

  void UpdateVelocity(SensorProximity * sp, bool superbot);

  void UpdateVelocity(SensorDistress * sd, bool superbot);

  /**
   * @brief Getter method for speed.
   *
   * @return The current speed.
   */

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
