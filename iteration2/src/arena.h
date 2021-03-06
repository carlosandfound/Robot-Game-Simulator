/**
 * @file arena.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_ARENA_H_
#define PROJECT_ITERATION2_SRC_ARENA_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cmath>
#include <iostream>
#include <vector>
#include "src/event_keypress.h"
#include "src/event_collision.h"
#include "src/event_proximity.h"
#include "src/event_distress_call.h"
#include "src/event_type_emit.h"
#include "src/robot.h"
#include "src/player.h"
#include "src/home_base.h"
#include "src/recharge_station.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
struct arena_params;

/**
 * @brief The main class for the simulation of a 2D world with many
 * robots and other obstacles running around.
 *
 * While GraphicsArenaViewer handles the graphics, Arena handles all the
 * data and all the entities. This means that the responsibility of
 * things like collision detection and entity management is on Arena.
 *
 */
class Arena {
 public:
  /**
   * @brief Arena's constructor.
   *
   * @param params A arena_params passed down from main.cc for the
   * initialization of Arena and the entities therein.
   *
   * Initialize all private variables and entities.
   */
  explicit Arena(const struct arena_params *const params);

  /**
   * @brief Arena's destructor. `delete` all entities created.
   */
  ~Arena();

  void HandleCollision(const ArenaEntity *const ent1,
                       const ArenaEntity *const ent2,
                       EventBaseClass *const event,
                       double angle);

  /**
   * @brief Advance the simulation by the specified # of steps.
   *
   * @param[in] dt The # of steps to increment by. This is
   * practically unused because the arena state is advanced
   * incrementally at a fixed rate.
   *
   * If `dt == 0`, `return` immediately. Otherwise calls
   * Arena::UpdateEntitiesTimestep() once.
   */
  void AdvanceTime(double dt);

  /**
  * @brief Handle the EventKeypress passed along by the GraphicsArenaViewer.
  *
  * @param e An event holding the key press.
  *
  * If `e`'s `enum event_commands` is `COM_UNKNOWN`, do nothing.
  */
  void Accept(const EventKeypress *const e);

  /**
   * @brief Reset all entities in Arena.
   */
  void Reset();

  /**
   * @brief Get the # of robots in Arena.
   *
   * @return # of robots in Arena.
   */
  unsigned int n_robots() const { return n_robots_; }

  /**
   * @brief Get # of obstacles in Arena.
   *
   * @return # of obstacles in Arena.
   */
  unsigned int n_obstacles() const { return n_obstacles_; }

  /**
   * @brief Get a list of all obstacles (Obstacle) (i.e. non-mobile entities in
   * Arena).
   *
   * @return Pointers to obstacles in a vector.
   */
  std::vector<class Obstacle *> obstacles();

  /**
   * @brief Get a list of all mobile entities (ArenaMobileEntity) in Arena.
   *
   * @return Pointers to mobile entities in a vector.
   */
  std::vector<class ArenaMobileEntity *> mobile_entities()
  { return mobile_entities_; }

  /**
   * @brief Get the Player (there's only 1) in Arena.
   *
   * @return A pointer to the Player.
   */
  class Player *player() const { return player_; }

  /**
   * @brief Get the Robot (there's only 5) in Arena.
   *
   * @return A pointer to the Robot.
   */
  class Robot *robot1() const { return robot1_; }
  class Robot *robot2() const { return robot2_; }
  class Robot *robot3() const { return robot3_; }
  class Robot *robot4() const { return robot4_; }
  class Robot *robot5() const { return robot5_; }

  /**
   * @brief Get the HomeBase (there's only 1) in Arena.
   *
   * @return A pointer to the HomeBase.
   */
  class HomeBase *home_base() const { return home_base_; }

  /**
   * @brief Get the RechargeStation (there's only 1) in Arena.
   *
   * @return A pointer to the RechargeStation.
   */
  class RechargeStation *recharge_station() const { return recharge_station_; }

  /**
   * @brief Win stats.
   *
   * @return The number of times the player has won (i.e. freeze all 5 robots)
   */
  int win() const { return win_; }

  /**
   * @brief Lose stats.
   *
   * @return The number of times the player has lost (i.e. all robots become
   * superbots
   */
  int lose() const { return lose_; }

 private:
  /**
   * @brief Determine if any entities in the arena are overlapping.
   *
   * @return `true` if any 2 entities overlap, `false` if no entity overlap.
   *
   * Currently unimplemented.
   */
  bool any_entities_overlap(void);

  /**
   * @brief Determine if entity is within range of proximity sensor of a robot.
   * If so, have it bounce off of the sensing robot at angle of reflection
   * to avoid contact. This is conceptually similar to CheckForEntityCollision()
   *
   * @param ent1 Robot with sensor.
   * @param ent2 Entity being sensed.
   * @param ec Pointer to a proximity event.
   *
   * This method does not return anything. All information related to the
   * detected proximity is stored in the EventProximity parameter passed in.
   */
  void CheckForEntityProximity(const class Robot *const sensing,
                               const class ArenaEntity *const sensed,
                               EventProximity *const ep);

  /**
   * @brief Determine if two entities have collided in the Arena. Collision is
   * defined as the distance between two entities being less than a run-time
   * parameter (specifically, collision_delta, which is set in main.cc).
   *
   * @param ent1 Entity #1.
   * @param ent2 Entity #2.
   * @param ec Pointer to a collision event.
   * @param collision_delta The minimum distance between two entities before
   * collision occurs.
   *
   * This method does not return anything. All information related to the
   * detected collision is stored in the EventCollision parameter passed in.
   */
  void CheckForEntityCollision(const class ArenaEntity *const ent1,
                               const class ArenaEntity *const ent2,
                               EventCollision *const ec,
                               double collision_delta);

  /**
   * @brief Determine if a particular entity has gone out of the boundaries of
   * the simulation (i.e. has collided with any one of the walls).
   *
   * @param ent The entity to check.
   * @param ec Pointer to a collision event.
   *
   * This method does not return anything. All information related to the
   * detected collision is stored in the EventCollision parameter passed in.
   */
  void CheckForEntityOutOfBounds(const class ArenaMobileEntity *const ent,
                                 EventCollision *const ec);

  /**
   * @brief Update all entities for a single timestep.
   *
   * First calls each entity's TimestepUpdate method to update their speed,
   * heading angle, and position. Then check for collisions between entities
   * or between an entity and a wall.
   *
   * Some specific events are also checked. 1) If all robots are frozen, then
   * the player has won and Arena::Reset is called and game stats and game stats
   * are updated. 2) If Player touches the RechargeStation, then the Robot's
   * battery is completely recharged. 3) If all robots become superbots, then
   * the player has lost and Arena::Reset is called and game stats are updated.
   * 4) If the player runs out of battery, the game is simply reset but it is
   * neither won or lost
   */
  void UpdateEntitiesTimestep();

  /**
   * Under certain circumstance, the compiler requires that the assignment
   * operator is not defined. This `deletes` the default assignment operator.
   */
  Arena &operator=(const Arena &other) = delete;

  /**
   * Under certain circumstance, the compiler requires that the copy
   * constructor is not defined. This `deletes` the default copy constructor.
   */
  Arena(const Arena &other) = delete;

  // Dimensions of graphics window inside which robots must operate
  double x_dim_;
  double y_dim_;
  unsigned int n_robots_;
  unsigned int n_obstacles_;

  // Entities populating the arena
  Robot *robot1_;
  Robot *robot2_;
  Robot *robot3_;
  Robot *robot4_;
  Robot *robot5_;
  Player *player_;
  RechargeStation *recharge_station_;
  HomeBase *home_base_;
  std::vector<class ArenaEntity *> entities_;
  std::vector<class ArenaMobileEntity *> mobile_entities_;
  int win_;
  int lose_;
  int number_frozen_;
  int number_superbots_;
  int time_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ARENA_H_
