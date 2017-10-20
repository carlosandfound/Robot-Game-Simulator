/**
 * @file mobile_arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_H_
#define SRC_ARENA_MOBILE_ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "entity.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A mobile entity in the arena, capable of updating its own position
 * and/or velocity when asked by the simulation.
 *
 * All mobile entities must have a heading angle so that their orientation can
 * be properly drawn by the viwer.
 */
class MobileEntity : public Entity {
 public:
  MobileEntity(const Position& pos, const int rad ) : Entity(pos, rad) {}

  /**
   * @brief Get/Set the current heading angle for the entity.
   */
  virtual double heading_angle(void) const = 0;
  virtual void heading_angle(double heading_angle) = 0;

  /**
   * @brief Get/Set the current speed of an arena entity.
   */
  virtual double get_speed(void) const = 0;
  virtual void set_speed(double sp) = 0;

  /**
   * @brief Update an entity's position after the specified # of
   * timesteps has elapsed.
   */
  void TimestepUpdate() = 0;

 private:
};

#endif /* SRC_ARENA_MOBILE_ENTITY_H_ */
