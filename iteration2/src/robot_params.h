/**
 * @file robot_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_ROBOT_PARAMS_H_
#define PROJECT_ITERATION2_SRC_ROBOT_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_mobile_entity_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Inherits from arena_mobile_entity_params to set various
 * properties of the Robot.
 */
struct robot_params : public arena_mobile_entity_params {
  robot_params() :
      arena_mobile_entity_params(),
      battery_max_charge(100),
      angle_delta(10),
      speed_delta(1),
      max_speed(10) {}

  double battery_max_charge;
  uint angle_delta;
  double speed_delta;
  double max_speed;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ROBOT_PARAMS_H_
