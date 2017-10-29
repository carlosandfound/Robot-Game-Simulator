/**
 * @file home_base.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_HOME_BASE_H_
#define SRC_HOME_BASE_H_

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
 * Initially an immobile entity, it should be made to move during iteration 1.
 */

class HomeBase: public Robot {
 public:
  explicit HomeBase(const struct robot_params* const params) :
    Robot(params) {
      this -> heading_angle(80);
  }
  std::string get_name(void) const override { return "Home Base"; }
};

NAMESPACE_END(csci3081);

#endif /* SRC_HOME_BASE_H_ */
