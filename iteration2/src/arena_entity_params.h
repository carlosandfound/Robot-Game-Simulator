/**
 * @file arena_entity_params.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_ARENA_ENTITY_PARAMS_H_
#define PROJECT_ITERATION2_SRC_ARENA_ENTITY_PARAMS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <nanogui/nanogui.h>
#include "src/common.h"
#include "src/color.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Structure Definitions
 ******************************************************************************/
/**
 * @brief Struct holding parameters for initializing ArenaEntity.
 *
 * Since ArenaEntity is a base class, this struct is also a "base class" in
 * some sense. It is meant to be inherited/extended by other structs, such as
 * arena_mobile_entity_params.
 */
struct arena_entity_params {
  arena_entity_params() : radius(20.0), pos(Position(700, 700)),
  color(Color(900, 300, 200, 900)) {}
  double radius;
  Position pos;
  Color color;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION2_SRC_ARENA_ENTITY_PARAMS_H_ */
