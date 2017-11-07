/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION1_SRC_POSITION_H_
#define PROJECT_ITERATION1_SRC_POSITION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
 NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A simple representation of a position of an entity within the arena.
 */
struct Position {
 public:
  Position(void) : x_(0), y_(0) {}
  Position(double in_x, double in_y) : x_(in_x), y_(in_y) { }

  double x;
  double y;
};

NAMESPACE_END(csci3081);

#endif  //  PROJECT_ITERATION1_SRC_POSITION_H_
