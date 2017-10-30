/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION1_SRC_HOME_BASE_H_
#define PROJECT_ITERATION1_SRC_HOME_BASE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

#include <string>
#include "src/home_base_params.h"
#include "src/arena_mobile_entity.h"
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The goal the the robot is trying to drive to within the arena.
 *
 * HomeBase now inherits from robot to become a mobile entity.
 */

class HomeBase: public Robot {
 public:
  explicit HomeBase(const struct robot_params* const params) :
    Robot(params) {}
  std::string get_name(void) const override { return "Home Base"; }
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION1_SRC_HOME_BASE_H_ */
