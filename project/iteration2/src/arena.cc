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
#include "src/arena_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params *const params) :
    x_dim_(params->x_dim),
    y_dim_(params->y_dim),
    n_robots_(5),
    n_obstacles_(static_cast<unsigned int>(params->n_obstacles)),
    player_(new Player(&params->robot)),
    robot1_(new Robot(&params->robots[0])),
    robot2_(new Robot(&params->robots[1])),
    robot3_(new Robot(&params->robots[2])),
    robot4_(new Robot(&params->robots[3])),
    robot5_(new Robot(&params->robots[4])),
    recharge_station_(new RechargeStation(params->recharge_station.radius,
                                          params->recharge_station.pos,
                                          params->recharge_station.color)),
    home_base_(new HomeBase(&params->home_base)),
    entities_(),
    mobile_entities_(),
    number_frozen_(0),
    number_superbots_(0),
    win_(0),
    lose_(0) {
  saved_params = params;
  entities_.push_back(player_);
  mobile_entities_.push_back(player_);
  entities_.push_back(robot1_);
  mobile_entities_.push_back(robot1_);
  entities_.push_back(robot2_);
  mobile_entities_.push_back(robot2_);
  entities_.push_back(robot3_);
  mobile_entities_.push_back(robot3_);
  entities_.push_back(robot4_);
  mobile_entities_.push_back(robot4_);
  entities_.push_back(robot5_);
  mobile_entities_.push_back(robot5_);

  entities_.push_back(recharge_station_);

  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);

  for (size_t i = 0; i < n_obstacles_; ++i) {
    entities_.push_back(new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color));
  } /* for(i..) */
}

Arena::~Arena() {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::Reset() {
  number_frozen_ = 0;
  number_superbots_ = 0;
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle *> Arena::obstacles() {
  std::vector<Obstacle *> res;
  for (auto ent : entities_) {
    auto *o = dynamic_cast<Obstacle *>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */

void Arena::AdvanceTime(double dt) {
  time_++;
  if (dt == 0)
    return;
  for (size_t i = 0; i < 1; ++i) {
    UpdateEntitiesTimestep();
  } /* for(i..) */
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep() {

  std::cout << number_frozen_ << '\n';
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
  if (player_->get_battery_level() <= 0) {
    Reset();
    time_ = 0;
  }

  if ((player_->frozen()) && (player_->time_frozen() == time_)) {
    player_->frozen(false);
    player_->set_speed(5);
  }

  /*
   * Next, check if the robot has collided with the recharge station or the home
   * base. These need to be before the general collisions, which can move the
   * robot away from these "obstacles" before the "collisions" have been
   * properly processed.
   */

  EventCollision ec;
  EventProximity ep;
  EventDistressCall ed;
  EventTypeEmit et;

  CheckForEntityCollision(player_, home_base_, &ec,
    player_->get_collision_delta());
  if (ec.collided()) {
    player_->Accept(&ec);
    // Reset();
  }

  for (uint i = 0; i < n_obstacles_; i++) {
    CheckForEntityCollision(player_, obstacles()[i], &ec,
                            player_->get_collision_delta());

    if (ec.collided()) {
      player_->Accept(&ec);

      if (obstacles()[i] == recharge_station_) {
        EventRecharge er;
        player_->Accept(&er);
      }
    }
  }

  /*
   * Finally, some pairs of entities may now be close enough to be considered
   * colliding, send collision events as necessary.
   *
   * When something collides with an immobile entity, the immobile entity does
   * not move (duh), so no need to send it a collision event.
   */
  for (auto ent : mobile_entities_) {
    // Check if it is out of bounds. If so, use that as point of contact.
    CheckForEntityOutOfBounds(ent, &ec);

    // If not at wall, check if colliding with any other entities (not itself)
    if (!ec.collided()) {
      for (size_t i = 0; i < entities_.size(); ++i) {
        if (entities_[i] == ent) {
          continue;
        }
        /*
        check for proximity event of robot with any other entity that
        isn't home base or is emitting a distress signal
        */
        if ((ent->get_entity_type_id() == 1) &&
            (entities_[i]->get_entity_type_id() != 2)) {
              if (entities_[i]->get_entity_type_id() == 1) {
                if (dynamic_cast<Robot *> (entities_[i]) ->
                get_distress_sensor()->output() == 0) {
                  CheckForEntityProximity(dynamic_cast<Robot *> (ent),
                                          entities_[i], &ep);
                }
              } else {
                CheckForEntityProximity(dynamic_cast<Robot *> (ent),
                                        entities_[i], &ep);
                }
        }
        // robot's proximity sensor detects an entity
        if ((ep.detected()) && !(dynamic_cast<Robot *> (ent)->is_superbot())) {
          dynamic_cast<Robot *> (ent) -> Accept(&ep);
      } else {
          CheckForEntityCollision(ent, entities_[i], &ec,
          ent->get_collision_delta());
          if (ec.collided()) {
            // player collides with a robot
            if (ent->get_entity_type_id() == 0 &&
              entities_[i]->get_entity_type_id() == 1) {
                // player collides with a superbot
                // player freezes for 100 iterations
                if ((dynamic_cast<Robot *> (entities_[i])->is_superbot()) &&
                    (!player_->frozen())) {
                      player_->frozen(true);
                      player_->time_frozen(time_+100);
                      player_->set_speed(0);
                }
                // player collides with a robot whose distres sensor is off
                // robot then freezes until another robot or superbot touches it
                if (dynamic_cast<Robot *> (entities_[i])->get_distress_sensor()
                  ->output() == 0) {
                    if (!dynamic_cast<Robot *> (entities_[i])->is_superbot()) {
                      number_frozen_++;
                      if (number_frozen_ == 5) {
                        win_++;
                        time_ = 0;
                        Reset();
                      }
                    }
                    ed.set_distress_status(true);
                    dynamic_cast<Robot *> (entities_[i])->Accept(&ed);
                    bool new_status = dynamic_cast<Robot *> (entities_[i])->
                                      get_distress_sensor()->output();
                    ed.set_distress_status(new_status);
                  }
                  // robot collides with home base to become a superbot
                  // superbots are the color purple
                } else if (ent->get_entity_type_id() == 1 &&
                  entities_[i]->get_entity_type_id() == 2 &&
                  !dynamic_cast<Robot *>(ent)->is_superbot()) {
                    ent->set_color(Color(900, 300, 200, 900));
                    dynamic_cast<Robot *>(ent)->Transform();
                    number_superbots_++;
                    // lose when all 5 robots become superbots
                    if (number_superbots_ == 5) {
                      lose_++;
                      time_ = 0;
                      Reset();
                    }
                    // robot/superbot collides with another robot
                    // turn off distess signal and unfreeze robot
                  } else if (ent->get_entity_type_id() == 1 &&
                    entities_[i]->get_entity_type_id() == 1) {
                      ed.set_distress_status(false);
                      ep.detected(false);
                      dynamic_cast<Robot *> (ent)->Accept(&ed);
                      dynamic_cast<Robot *> (entities_[i])->Accept(&ed);
                      if ((dynamic_cast<Robot *> (ent)->get_speed() == 0) ||
                      (dynamic_cast<Robot *> (entities_[i])->get_speed() == 0))
                      {
                        number_frozen_--;
                      }
                    }
            ent->Accept(&ec);

            // player collides with recharge station
            if ((ent == player_) && (entities_[i] == recharge_station_)) {
              EventRecharge er;
              player_->Accept(&er);
            }
            break;
          }
        }
      } /* for(i..) */
    } /* else */
    ent->Accept(&ec);
  } /* for(ent..) */
} /* UpdateEntities() */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity *const ent,
                                      EventCollision *const event) {
  if (ent->get_pos().x + ent->radius() >= x_dim_) {
    // Right Wall
    event->collided(true);
    event->point_of_contact(Position(x_dim_, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle() - 180);
  } else if (ent->get_pos().x - ent->radius() <= 0) {
    // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y));
    event->angle_of_contact(ent->get_heading_angle() - 180);
  } else if (ent->get_pos().y + ent->radius() >= y_dim_) {
    // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x, y_dim_));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().y - ent->radius() <= 0) {
    // Top Wall
    event->collided(true);
    event->point_of_contact(Position(0, y_dim_));
    event->angle_of_contact(ent->get_heading_angle());
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

void Arena::CheckForEntityProximity(const Robot *const sensing,
                                    const ArenaEntity *const sensed,
                                    EventProximity *const event) {
  /* Note: this assumes circular entities */
  double sensing_x = sensing->get_pos().x;
  double sensing_y = sensing->get_pos().y;
  double sensed_x = sensed->get_pos().x;
  double sensed_y = sensed->get_pos().y;
  double deltaX = sensed_x - sensing_x;
  double deltaY = sensed_y - sensing_y;
  double dist = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));
  if (dist > (sensing->get_left_proximity_sensor()->
    get_range() + sensed->radius())) {
      event->detected(false);
    } else {
      // Populate the proximity event.
      // detected is true
      double triangle_theta = fabs(std::atan(sensed->radius()/dist)*(180/3.14));
      double distance_theta = fabs(std::atan2(deltaY, deltaX)*(180/3.14));
      double sensor_lower = sensing-> get_heading_angle() -
        (static_cast<int> ((sensing->get_left_proximity_sensor()->
            get_fov())/2));
      double sensor_upper = sensing-> get_heading_angle() +
        (static_cast<int> ((sensing->get_left_proximity_sensor()->
            get_fov())/2));
      double sensed_lower = distance_theta - triangle_theta;
      double sensed_upper = distance_theta + triangle_theta;

      if (sensing->get_left_proximity_sensor()->
        in_range(std::abs(sensor_lower), std::abs(sensor_upper),
        std::abs(sensed_lower), std::abs(sensed_upper))) {
          event->detected(true);

          double angle = std::asin(std::abs(sensed_x - sensing_x) / dist);

          if ((sensed_x - sensing_x) > 0) {
            if ((sensed_y - sensing_y) > 0) {
              // lower right
              event->point_of_detection(
                  {
                      sensing_x + std::sin(angle) * sensing->radius(),
                      sensing_y + std::cos(angle) * sensing->radius()
                  });
              angle = M_PI_2 - angle;
            } else if ((sensed_y - sensing_y) < 0) {
              // upper right
              event->point_of_detection(
                  {
                      sensing_x + std::sin(angle) * sensing->radius(),
                      sensing_y - std::cos(angle) * sensing->radius()
                  });
              angle += (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
              // 0 or 360 deg
              event->point_of_detection(
                  {
                      sensing_x + sensing->radius(),
                      sensing_y
                  });
              angle = 0;
            }
          } else if ((sensed_x - sensing_x) < 0)  {
            if ((sensed_y - sensing_y) > 0) {
              // lower left
              event->point_of_detection(
                  {
                      sensing_x - std::sin(angle) * sensing->radius(),
                      sensing_y + std::cos(angle) * sensing->radius()
                  });
              angle += M_PI_2;
            } else if ((sensed_y - sensing_y) < 0) {
              // upper left
              event->point_of_detection(
                  {
                      sensing_x - std::sin(angle) * sensing->radius(),
                      sensing_y - std::cos(angle) * sensing->radius()
                  });
              angle = (M_PI_2 * 2) + (M_PI_2 - angle);
            } else {  // if ((ent2_y - ent1_y) == 0)
              // 180 deg
              event->point_of_detection(
                  {
                      sensing_x - sensing->radius(),
                      sensing_y
                  });
              angle = M_PI;
            }
          } else {  // if ((ent2_x - ent1_x) == 0)
            if ((sensed_y - sensing_y) > 0) {
              // 90 deg
              event->point_of_detection(
                  {
                      sensing_x,
                      sensing_y + sensing->radius()
                  });
              angle = M_PI_2;
            } else if ((sensed_y - sensing_y) < 0) {
              // 270 deg
              event-> point_of_detection(
                {
                    sensing_x,
                    sensing_y - sensing->radius()
                });
              angle = (3 * M_PI_2);
            } else {  // if ((ent2_y - ent1_y) == 0)
              // completely overlap, which is theoretically impossible...
              std::cerr << sensing->get_name() <<
              " is in complete overlap with " << sensed->get_name() << ".\n";
              assert(false);
            }
          }

          event->angle_of_detection((M_PI - angle) / M_PI * 180);
        }
      }
    }

void Arena::CheckForEntityCollision(const ArenaEntity *const ent1,
                                    const ArenaEntity *const ent2,
                                    EventCollision *const event,
                                    double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x;
  double ent1_y = ent1->get_pos().y;
  double ent2_x = ent2->get_pos().x;
  double ent2_y = ent2->get_pos().y;
  double dist = std::sqrt(
      std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));
  if (dist > ent1->radius() + ent2->radius() + collision_delta) {
    event->collided(false);
  } else {
    // Populate the collision event.
    // Collided is true
    // Point of contact is point along perimeter of ent1
    // Angle of contact is angle to that point of contact
    // ref: https://stackoverflow.com/a/1736741
    event->collided(true);

    double angle = std::asin(std::abs(ent2_x - ent1_x) / dist);

    if ((ent2_x - ent1_x) > 0) {
      if ((ent2_y - ent1_y) > 0) {
        // lower right
        event->point_of_contact(
            {
                ent1_x + std::sin(angle) * ent1->radius(),
                ent1_y + std::cos(angle) * ent1->radius()
            });
        angle = M_PI_2 - angle;
      } else if ((ent2_y - ent1_y) < 0) {
        // upper right
        event->point_of_contact(
            {
                ent1_x + std::sin(angle) * ent1->radius(),
                ent1_y - std::cos(angle) * ent1->radius()
            });
        angle += (3 * M_PI_2);
      } else {  // if ((ent2_y - ent1_y) == 0)
        // 0 or 360 deg
        event->point_of_contact(
            {
                ent1_x + ent1->radius(),
                ent1_y
            });
        angle = 0;
      }
    } else if ((ent2_x - ent1_x) < 0)  {
      if ((ent2_y - ent1_y) > 0) {
        // lower left
        event->point_of_contact(
            {
                ent1_x - std::sin(angle) * ent1->radius(),
                ent1_y + std::cos(angle) * ent1->radius()
            });
        angle += M_PI_2;
      } else if ((ent2_y - ent1_y) < 0) {
        // upper left
        event->point_of_contact(
            {
                ent1_x - std::sin(angle) * ent1->radius(),
                ent1_y - std::cos(angle) * ent1->radius()
            });
        angle = (M_PI_2 * 2) + (M_PI_2 - angle);
      } else {  // if ((ent2_y - ent1_y) == 0)
        // 180 deg
        event->point_of_contact(
            {
                ent1_x - ent1->radius(),
                ent1_y
            });
        angle = M_PI;
      }
    } else {  // if ((ent2_x - ent1_x) == 0)
      if ((ent2_y - ent1_y) > 0) {
        // 90 deg
        event->point_of_contact(
            {
                ent1_x,
                ent1_y + ent1->radius()
            });
        angle = M_PI_2;
      } else if ((ent2_y - ent1_y) < 0) {
        // 270 deg
        event->point_of_contact(
            {
                ent1_x,
                ent1_y - ent1->radius()
            });
        angle = (3 * M_PI_2);
      } else {  // if ((ent2_y - ent1_y) == 0)
        // completely overlap, which is theoretically impossible...
        std::cerr << ent1->get_name() << " is in complete overlap with "
                  << ent2->get_name() << ".\n";
        assert(false);
      }
    }

    event->angle_of_contact((M_PI - angle) / M_PI * 180);
  }
} /* entities_have_collided() */

void Arena::Accept(const EventKeypress *const e) {
  // don't handle unsupported keys
  if ((e->GetCmd() != COM_UNKNOWN) && (player_->frozen() == false))
    player_->Accept(new EventCommand(e->GetCmd()));
} /* Accept */

NAMESPACE_END(csci3081);
