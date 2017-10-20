/**
 * @file mobile_arena_entity.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ARENA_MOBILE_ENTITY_VIRTUAL_H_
#define SRC_ARENA_MOBILE_ENTITY_VIRTUAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include "entity_virtual.h"

class MobileEntityVirtual : public EntityVirtual {
 public:
  MobileEntityVirtual(const Position& pos, const int rad)
   : EntityVirtual(pos, rad) {}

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

  void TimestepUpdate();

 private:
};

#endif /* SRC_ARENA_MOBILE_ENTITY_H_ */
