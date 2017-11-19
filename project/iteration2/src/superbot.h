/**
 * @file superbot.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_SUPERBOT_H_
#define PROJECT_ITERATION2_SRC_SUPERBOT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/robot.h"
#include "src/arena_mobile_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Class representing a mobile superbot within the arena.
 *
 * superbots have the capability of updating their own position when asked, and
 * also track their own velocity and heading. They have 2 proximity sensors,
 * a distress call sensor, an entity type sensor, and a touch sensor. SuperBots
 * can unfreeze all Robots and freeze the Player.
 *
 * superbots don't avoid collisions with a detected Player. Superbots have the
 * same max and min speeds/angles and battery as robots do.
 */
class Superbot : public Robot {
 public:
  /**
   * @brief Constructor.
   *
   * @param params Same parameters as robot except that it's color is the
   * default robot_params color (i.e. PURPLE) while robots are green.
   */
  explicit Superbot(const struct robot_params* const params);

  std::string get_name() const override {
    return "superbot" + std::to_string(id_);
  }

 private:
  static unsigned int next_id_;
  int id_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SUPERBOT_H_
