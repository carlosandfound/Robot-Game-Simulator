/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>

#include "src/arena.h"
#include "src/robot.h"
#include "src/obstacle.h"
#include "src/event_collision.h"
#include "src/arena_params.h"
#include "src/recharge_station.h"
#include "src/home_base.h"
#include "src/event_recharge.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params* const params) :
  x_dim_(params->x_dim), y_dim_(params->y_dim),
  n_robots_(1),
  n_obstacles_(params->n_obstacles),
  robot_(new Robot(&params->robot)),
  recharge_station_(new RechargeStation(params->recharge_station.radius,
    params->recharge_station.pos,
    params->recharge_station.color)),
  home_base_(new HomeBase(&params->home_base)),
  entities_(),
  mobile_entities_() {
  robot_->heading_angle(80);
  entities_.push_back(robot_);
  mobile_entities_.push_back(robot_);
  entities_.push_back(recharge_station_);
  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);
  win = false;
  lose = false;

  for (size_t i = 0; i < n_obstacles_; ++i) {
    entities_.push_back(new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color));
  } /* for(i..) */
}

Arena::~Arena(void) {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::Reset(void) {
for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle*> Arena::obstacles(void) {
  std::vector<Obstacle*> res;
  for (auto ent : entities_) {
    Obstacle* o = dynamic_cast<Obstacle*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */

void Arena::AdvanceTime(double dt) {
  std::cout << "Advancing simulation time by " << dt << " timesteps\n";
  for (size_t i = 0; i < 1; ++i) {
    UpdateEntitiesTimestep();
  } /* for(i..) */
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep(void) {
   /*
    * If the number randmly generated is 5 then home base changes direction to
    * a randomly generated angle between 0 and 360. Otherwise, home base
    * continues on the same direction
    */

    unsigned int seed = time(nullptr);
    int randNum = (rand_r(&seed) % 9);

    if (randNum == 5) {
      unsigned int seed2 = time(nullptr);
      int randAngle = (rand_r(&seed2) % 361);
      home_base_ -> heading_angle(randAngle);
    }

   /*
    * First, update the position of all entities, according to their current
    * velocities.
    */

  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */

  /*
   * Next, check if the robot has run out of battery
   */
  if (robot_->battery_level() <= 0) {
    lose = true;
  }


  /*
   * Next, check if the robot has collided with the recharge station or the home
   * base. These need to be before the general collisions, which can move the
   * robot away from these "obstacles" before the "collisions" have been
   * properly processed. Moreover, if the robot has collided with home base,
   * the game is won.
   */

  EventCollision ec;

  CheckForEntityCollision(robot_, home_base_, &ec, robot_->collision_delta());
  if (ec.collided()) {
      win = true;
  }

  CheckForEntityCollision(robot_, recharge_station_, &ec,
                          robot_->collision_delta());
  if (ec.collided()) {
    EventRecharge er;
    robot_->Accept(&er);
  }

  /*
   * Finally, some pairs of entities may now be close enough to be considered
   * colliding, send collision events as necessary.
   *
   * When something collides with an immobile entity, the immobile entity does
   * not move (duh), so no need to send it a collision event.
   */
  for (auto ent : mobile_entities_) {
    /* Check if it is out of bounds. If so, use that as point of contact. */
    CheckForEntityOutOfBounds(ent, &ec);

    /*
     * If not at wall, check if it is colliding with any other entities
     * (not itself)
     */
    if (!ec.collided()) {
      for (size_t i = 0; i < entities_.size(); ++i) {
        if (entities_[i] == ent) {
          continue;
        }

        /* Send collision event to robot if it collides with obstacles */
        CheckForEntityCollision(ent, entities_[i], &ec, ent->collision_delta());
        if (ec.collided()) {
          if (i >= 3 && ent == robot_) {
            robot_ -> UpdateCharge(&ec);
            robot_ -> UpdateVelocity(&ec);
          }
          break;
        }
      } /* for(i..) */
    } /* else */
    ent->Accept(&ec);
  } /* for(ent..) */
} /* UpdateEntities() */


/*
 * Check if entity has collided with a wall. If it has, then use the heading
 * angle to set the angle of contact of the event collision to the reflection
 * angle so that the entity bounces off at angle of reflection.
 */

/*
 * limit working dimension such that the left wall is at an x-coordinate of 200
 * so that the mobile entities work within limited dimension where they
 * they don't overlap with gui simulation controls/buttons.
 */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity * const ent,
                                     EventCollision * const event) {
  double heading_angle_ = ent -> heading_angle();
  if (ent->get_pos().x() + ent->radius() >= x_dim_) {  // Right Wall
    event->collided(true);
    event->point_of_contact(Position(x_dim_, ent->get_pos().y()));
    if ((heading_angle_ > 270) && (heading_angle_ < 360)) {
      event->angle_of_contact(-(270 - (heading_angle_ - 270)));
    } else {
      event->angle_of_contact(-(90 + (90 - heading_angle_)));
    }

  } else if (ent->get_pos().x() - ent->radius() <= 200) {  // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y()));
    if ((heading_angle_ > 180) && (heading_angle_ < 270)) {
      event->angle_of_contact(-(270 + (270 - heading_angle_)));
    } else {
      event->angle_of_contact(-(90 - (heading_angle_ - 90)));
    }
  } else if (ent->get_pos().y() + ent->radius() >= y_dim_) {  // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x(), y_dim_));
    if ((heading_angle_ > 180) && (heading_angle_ < 90)) {
      event->angle_of_contact(-(270 - (heading_angle_ - 90)));
    } else {
      event->angle_of_contact(-(270 + (90 - heading_angle_)));
    }
  } else if (ent->get_pos().y() - ent->radius() <= 0) {  // Top Wall
    event->collided(true);
    event->point_of_contact(Position(0, y_dim_));
    if ((heading_angle_ < 360) && (heading_angle_ > 270)) {
      event->angle_of_contact(-(90 - (heading_angle_ - 270)));
    } else {
      event->angle_of_contact(-(90 + (270 - heading_angle_)));
    }
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityCollision(const ArenaEntity* const ent1,
  const ArenaEntity* const ent2, EventCollision * const event,
  double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x();
  double ent1_y = ent1->get_pos().y();
  double ent2_x = ent2->get_pos().x();
  double ent2_y = ent2->get_pos().y();
  double dist = std::sqrt(std::pow(ent2_x - ent1_x, 2) +
                          std::pow(ent2_y - ent1_y, 2));

  if (dist > ent1->radius() + ent2->radius() + collision_delta) {
    event->collided(false);
  } else {
    /*
     * Populate the collision event.
     * Collided is true
     * Point of contact is point along perimeter of ent1
     * Angle of contact is angle to that point of contact
     */
    event->collided(true);
    double newAngle = (tan((ent1->radius()) / dist)) * (180/M_PI);

    /* 1st quadrant of the entity being collided by mobile entity */
    if ((ent1_x > ent2_x) && (ent1_y > ent2_y)) {
      event->angle_of_contact(-(360 - newAngle));
    } else if ((ent1_x < ent2_x) && (ent1_y > ent2_y)) {
      /* 2nd quadrant of the entity being collided by mobile entity */
      event->angle_of_contact(-(180 + newAngle));
    } else if ((ent1_x < ent2_x) && (ent1_y < ent2_y)) {
      /* 3rd quadrant of the entity being collided by mobile entity */
      event->angle_of_contact(-(180 - newAngle));
    } else if ((ent1_x > ent2_x) && (ent1_y < ent2_y)) {
      /* 4th quadrant of the entity being collided by mobile entity */
      event->angle_of_contact(-(0 + newAngle));
    } else {
      if (ent1 == robot_) {
        double heading_angle = robot_ -> heading_angle();
        if (heading_angle >= 0 && heading_angle < 180) {
          event->angle_of_contact(-(180 + heading_angle));
        } else {
          event->angle_of_contact(-(heading_angle - 180));
        }
        robot_ -> Accept(event);
      }
    }
  }
} /* entities_have_collided() */

/*
 * Get the command from the eventkeypress and pass on the event to robot
 */
void Arena::Accept(EventKeypress * e) {
  enum event_commands cmd = e->getCommand();
  EventCommand c(cmd);
  robot_ -> Accept(&c);
}

NAMESPACE_END(csci3081);
