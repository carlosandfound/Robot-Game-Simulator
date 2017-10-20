/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_H_
#define SRC_ARENA_ENTITY_H_

#include <string>
#include "position.h"

class Entity {
 public:
  Entity(const Position& pos, int rad) : position_(pos), radius_(rad) {}
  virtual ~Entity(void) {}

  /**
   * @brief Perform whatever updates are needed for a particular entity after 1
   * timestep.
   */
  virtual void TimestepUpdate() {}

  /**
  * @brief Setter and Getter for position. Defined here only (not in subclass)
  *
  */
  void set_position(const Position& pos) { position_ = pos; }
  const Position& get_position(void) const { return position_; }

  void set_radius(const int rad) { radius_ = rad; }
  const int& get_radius(void) const { return radius_; }

 private:
  Position position_;
  int radius_;
};

#endif /* SRC_ARENA_ENTITY_H_ */
