/**
 * @file sensor_distress.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_SENSOR_DISTRESS_H_
#define PROJECT_ITERATION3_SRC_SENSOR_DISTRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/event_distress_call.h"
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
 * call and 0 for none. The distress signal will only be turned on for a frozen
 * robot (i.e. not a superbot)
 */
class SensorDistress : public Sensor {
 public:
  /**
   * @brief constructor with sensor's robot user and field of view (fov) as
   * parameters.
   */
  explicit SensorDistress(double range):
    range_(range) {}

  /**
   * @brief Compute a new reading based on a distress event.
   *
   * Accept a distress event and changes the distress status based on the
   * position of the robot emitting the distress signal relative to the
   * field of view of the sensor.
   */
  void Accept(const EventDistressCall *const e);

  /**
   * @brief getter method that outputs the distress call status of the sensor.
   *
   * Should only output 1 when the distress signal is sensed within the
   * given range.
   *
   * @return 1 for a sensed call and 0 Otherwise
   */
  int output() { return status_; }

  void output(int s) {status_ = s;}

  int get_range() { return range_; }

  /**
   * @brief Reset sensor to it's original state
   */
  void Reset() override;

 private:
  double range_;
  int status_ = 0;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION3_SRC_SENSOR_DISTRESS_H_
