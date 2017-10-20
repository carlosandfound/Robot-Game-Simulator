/**
 * @file arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_ENTITY_VIRTUAL_H_
#define SRC_ARENA_ENTITY_VIRTUAL_H_

#include <string>
#include "position.h"

class EntityVirtual {
 public:
  EntityVirtual(const Position& pos, int rad) : position_(pos), radius_(rad) {}
  virtual ~EntityVirtual(void) {}

  /**
   * @brief Perform whatever updates are needed for a particular entity after 1
   * timestep.
   */
  virtual void TimestepUpdate() {}

  virtual void set_position(const Position& pos) = 0;
  virtual const Position& get_position(void) const = 0;

  virtual void set_radius(const int& rad) = 0;
  virtual const int& get_radius(void) const = 0;

protected:
  Position position_;
  int radius_;
};

#endif /* SRC_ARENA_ENTITY_H_ */
