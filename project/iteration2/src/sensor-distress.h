/**
 * @file sensor_distress.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_SENSOR_DISTRESS_H_
#define PROJECT_ITERATION2_SRC_SENSOR_DISTRESS_H_

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
 * @brief Class representing a distress sensor.
 *
 * The distress signal can be sensed when it is within a defined range, but the
 * direction of the signal can't be determined.Sensor output is 1 for a sensed
 * call and 0 for none.
 */
class SensorDistress : public Sensor {
 public:
  /**
   * @brief Default constructor.
   */
  SensorDistress();

  /**
   * @brief method to sense a distress call from the robot when at a defined
   * range
   *
   * Should only be activated when the distress signal is sensed within the
   * given range.
   *
   * @return 1 for a sensed call and 0 Otherwise
   */
  int is_sensed(class ArenaEntity *const ent);

 private:
  int sensed_call = 0;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SENSOR_DISTRESS_H_
