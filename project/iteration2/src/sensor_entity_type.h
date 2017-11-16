/**
 * @file sensor_entity_type.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_SENSOR_ENTITY_TYPE_H_
#define PROJECT_ITERATION2_SRC_SENSOR_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/event_type_emit.h"
#include "src/sensor.h"
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
/**
 * @brief Class representing entity type sensor
 *
 * The class can sense the type of the entity emitting the signal within a
 * defined range. However, the direction of the signal can't be determined.
 */
class SensorEntityType : public Sensor {
 public:
  /**
   * @brief constructor with sensor's robot user and field of view (fov) as
   * parameters.
   */
  //  SensorEntityType();
  SensorEntityType(const Robot * robot, double range):
    robot_(robot),
    range_(range),
    activated_(0) {}

  /**
   * @brief Compute a new reading based on a enit type emit event.
   *
   * Can only sense the entity when it's within the defined range. The
   * direction of the signal can't be determined. If entity is within range,
   * the type variable is set to the entity type being sensed.
   */
  void Accept(const EventTypeEmit *const ent);

  /**
   * @brief getter method that returns the entity type of the robot
   *
   * Can only sense the entity when it's within the defined range. The
   * direction of the signal can't be determined.
   */
  enum entity_type output () const { return type_; }

  int get_range() { return range_; }

  void Reset() override;

 private:
  const Robot * robot_;
  double range_;
  enum entity_type type_ = NONE;
  int activated_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SENSOR_ENTITY_TYPE_H_
