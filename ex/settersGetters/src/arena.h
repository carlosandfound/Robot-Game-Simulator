/**
* @file robot_arena.h
*
* @copyright 2017 3081 Staff, All rights reserved.
*/

#ifndef SRC_ARENA_H_
#define SRC_ARENA_H_

/*******************************************************************************
* Includes
******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>

#include "robot.h"
#include "robot_virtual.h"

class Arena {
public:
  explicit Arena();
  ~Arena(void);

  void AddRobot(const Position& pos, const int rad);
  void AddRobotVirtual(const Position& pos, const int rad);

  /**
  * @brief Advance the simulation by the specified # of steps.
  */
  void AdvanceTime();


private:
  /**
  * @brief Determine if two entities have collided in the arena. Collision is
  * defined as the difference between the extents of the two entities being less
  * than a run-time parameter.
  *
  * @param ent1 Entity #1.
  * @param ent2 Entity #2.
  * @param pointer to a collision event
  *
  * Collision Event is populated appropriately.
  */

  bool CheckForCollision(Entity* ent1, Entity* ent2);

  bool CheckForCollisionVirtual(EntityVirtual* ent1, EntityVirtual* ent2);

  /**
  * @brief Update all entities for a single timestep
  */
  void UpdateEntities(void);

  // Entities populating the arena
  int n_robots_;
  Entity* robots_[3];
  int n_robots_virtual_;
  EntityVirtual* robots_virtual_[3];
};

#endif  // SRC_ARENA_H_
