/**
 * @file robot_motion_behavior.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_ROBOT_MOTION_BEHAVIOR_H_
#define SRC_ROBOT_MOTION_BEHAVIOR_H_

#include "mobile_entity.h"
#include "mobile_entity_virtual.h"

class MotionBehavior {
 public:
  MotionBehavior(void) {}

  /**
   * @brief Update the position for an ArenaEntity, based on its current
   * position and velocity.
   *
   * @param[in] ent The entitity to update.
   */
  void UpdatePosition(class MobileEntity * const ent);
  void UpdatePosition(class MobileEntityVirtual * const ent);
};

#endif /* SRC_ROBOT_MOTION_BEHAVIOR_H_ */
