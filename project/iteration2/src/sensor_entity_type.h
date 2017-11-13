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
#include "src/sensor.h"

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
   * @brief Default constructor.
   */
  SensorEntityType();

  /**
   * @brief method that senses the entity within the defined range
   *
   * Can only sense the entity when it's within the defined range. The
   * direction of the signal can't be determined.
   *
   * @return the enumerated entity type
   */
  enum entity_type sense_entity(class ArenaEntity *const ent);
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SENSOR_ENTITY_TYPE_H_
