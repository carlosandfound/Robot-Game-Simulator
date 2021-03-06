/**
 * @file sensor.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_SENSOR_H_
#define PROJECT_ITERATION3_SRC_SENSOR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_base_class.h"
#include "src/event_recharge.h"
#include "src/event_collision.h"
#include "src/event_command.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Base class for sensors. Should be inherited by classes like
 * SensorTouch, SensorDistress, SensorProximity, SensorEntityType
 */
class Sensor {
 public:
  /**
   * @brief Constructor. Creates a deactivated sensor.
   */
  Sensor() : activated_(0) {}

  /**
   * @brief Default destructor.
   */
  virtual ~Sensor() = default;

  /**
   * @brief Accept a recharge event.
   *
   * @param e The recharge event.
   */
  void Accept(__unused const EventRecharge *const e);

  /**
   * @brief Pass along a collision event (from Arena) to the sensor.
   *
   * This method provides a framework in which sensors can get different types
   * of collision information from different sources.
   *
   * @param e The collision event.
   */
  void Accept(const EventCollision *const e);

  /**
   * @brief Accept a command event from arena that changes the entity's
   * heading or speed.
   *
   * @param e The command to process.
   */
  void Accept(const EventCommand *const e);

  /**
   * @brief Reset the sensor to its newly constructed state.
   */
  virtual void Reset() = 0;

 private:
  int activated_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_SENSOR_H_
