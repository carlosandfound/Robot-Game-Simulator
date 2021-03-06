/**
 * @file recharge_station.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_RECHARGE_STATION_H_
#define PROJECT_ITERATION3_SRC_RECHARGE_STATION_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "src/obstacle.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A class representing a recharge station within the Arena that is used
 * to recharge the player's battery.
 */
class RechargeStation : public Obstacle {
 public:
  /**
   * @brief Constructor. Simply calls Obstacle's constructor, as
   * RechargeStation is currently just a special Obstacle.
   *
   * @param radius The radius of the RechargeStation.
   * @param pos The permanent position of the RechargeStation.
   * @param color The color of the RechargeStation.
   */
  RechargeStation(double radius, const Position &pos,
                  const Color &color) :
      Obstacle(radius, pos, color) {}

  /**
   * @brief Get the name of the RechargeStation for visualization purposes, and
   * to aid in debugging.
   *
   * @return Name of the RechargeStation.
   */
  std::string get_name() const override {
    return "Recharge Station";
  }

  /**
   * @brief Getter method for the recharge station's entity type id, which is 3
   */
  int get_entity_type_id() const override { return 3; }
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_RECHARGE_STATION_H_
