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
#include "src/arena_immobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class HomeBase: public ArenaImmobileEntity {
 public:
  HomeBase(const struct home_base_params* const params) :
    ArenaImmobileEntity(params->radius, params->pos, params->color) {
  }
  std::string name(void) const { return "Home Base"; }
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION1_SRC_HOME_BASE_H_ */
