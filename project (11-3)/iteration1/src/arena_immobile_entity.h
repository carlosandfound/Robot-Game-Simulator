/**
 * @file arena_immobile_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION1_SRC_ARENA_IMMOBILE_ENTITY_H_
#define PROJECT_ITERATION1_SRC_ARENA_IMMOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/arena_entity.h"
#include "src/color.h"


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An immobile entity in the arena.
 *
 * Immobile entities cannot move, and therefore do not need to override the
 * \ref TimestepUpdate() function.
 */

class ArenaImmobileEntity : public ArenaEntity {
 public:
  ArenaImmobileEntity(double radius, const Position& pos,
                    const Color& color) :
      ArenaEntity(radius, pos, color) {}
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION1_SRC_ARENA_IMMOBILE_ENTITY_H_
