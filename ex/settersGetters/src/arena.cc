/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>
#include <iostream>

#include "arena.h"
#include "robot.h"
#include "robot_virtual.h"

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena() :
  n_robots_virtual_(0), n_robots_(0) {
}

Arena::~Arena(void) {
  for (int i=0;i<n_robots_;i++) {
    delete robots_[i];
  } /* for(ent..) */
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::AddRobotVirtual(const Position& pos, const int rad) {
  robots_virtual_[n_robots_virtual_] = new RobotVirtual( pos, rad);
  n_robots_virtual_++;
}

void Arena::AddRobot(const Position& pos, const int rad) {
  robots_[n_robots_] = new Robot( pos, rad );
  n_robots_++;
}

void Arena::AdvanceTime() {
  UpdateEntities();
}

void Arena::UpdateEntities(void) {

  // Update the position of all entities.
  for (int i=0; i<n_robots_; i++) {
    robots_[i]->TimestepUpdate();
  }
  // Some pairs of entities may now be close enough to be colliding
  for (int i=0; i<n_robots_; i++) {
    for (int j=i+1; j<n_robots_; j++) {
      if (CheckForCollision(robots_[i],robots_[j])) {
        std::cout << "Robot "<< i << " colliding with robot " << j << "\n";
      }
    }
  }

  // Same thing, except for robots with virtual setters/getters
  for (int i=0; i<n_robots_virtual_; i++) {
    robots_virtual_[i]->TimestepUpdate();
  }
  // Some pairs of entities may now be close enough to be colliding
  for (int i=0; i<n_robots_virtual_; i++) {
    for (int j=i+1; j<n_robots_virtual_; j++) {
      if (CheckForCollisionVirtual(robots_virtual_[i],robots_virtual_[j])) {
        std::cout << "Virtual robot "<< i << " colliding with robot " << j << "\n";
      }
    }
  }
}

bool Arena::CheckForCollision(Entity* ent1, Entity* ent2 ) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_position().x;
  double ent1_y = ent1->get_position().y;
  double ent2_x = ent2->get_position().x;
  double ent2_y = ent2->get_position().y;
  double dist = std::sqrt(std::pow(ent2_x - ent1_x, 2) +
                          std::pow(ent2_y - ent1_y, 2));
  if (dist > (ent1->get_radius() + ent2->get_radius())) {
    return false;
  } else {
    return true;
  }
} /* CheckForCollision() */

bool Arena::CheckForCollisionVirtual(EntityVirtual* ent1,
  EntityVirtual* ent2 ) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_position().x;
  double ent1_y = ent1->get_position().y;
  double ent2_x = ent2->get_position().x;
  double ent2_y = ent2->get_position().y;
  double dist = std::sqrt(std::pow(ent2_x - ent1_x, 2) +
                          std::pow(ent2_y - ent1_y, 2));
  if (dist > (ent1->get_radius() + ent2->get_radius())) {
    return false;
  } else {
    return true;
  }
} /* CheckForCollisionVirtual() */
