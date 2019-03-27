/**
 * @file motion_handler_home_base.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_MOTION_HANDLER_HOME_BASE_H_
#define PROJECT_ITERATION3_SRC_MOTION_HANDLER_HOME_BASE_H_

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
 * on collisions.
 *
 * Currently, both wheels are always going at maximum speed, and
 * cannot be controlled independently.
 */
class MotionHandlerHomeBase : public MotionHandler {
 public:
  /**
   * @brief Default constructor.
   */
  MotionHandlerHomeBase();

  /**
  * @brief Update the speed and the heading angle according to the sensor
  * readings.
  *
  * @param st A SensorTouch to be read.
  */
  void UpdateVelocity(SensorTouch st) override;

 private:
  double heading_angle_;
  double speed_;
  double max_speed_;
  double max_angle_;
  double speed_delta_;
  double angle_delta_;
};

NAMESPACE_END(csci3081);

#endif   // PROJECT_ITERATION3_SRC_MOTION_HANDLER_HOME_BASE_H_
