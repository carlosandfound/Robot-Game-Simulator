/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorProximity::Accept(const EventProximity *const e) {
  // Determine if the sensor is activated or deactivated.
  if (e->detected()) {
    activated(1);
    point_of_detection_ = e->point_of_detection();
    angle_of_detection_ = e->angle_of_detection();
  } else {
    activated(0);
  }
}

bool SensorProximity::In_Range(double sensor_lower, double sensor_upper,
  double sensed_lower, double sensed_upper) {
    if (sensor_lower > sensor_upper) {
      double distanceToCrossing = 360.0 - sensor_lower;
      sensor_lower = static_cast<int>(sensor_lower+distanceToCrossing) % 360;
      sensor_upper = sensor_upper + distanceToCrossing;
      sensed_lower = static_cast<int>(sensed_lower+distanceToCrossing) % 360;
      sensed_upper = static_cast<int>(sensed_upper+distanceToCrossing) % 360;
    }
    if (sensed_lower > sensed_upper) {
      double distanceToCrossing = 360.0 - sensed_lower;
      sensor_lower = static_cast<int>(sensor_lower+distanceToCrossing) % 360;
      sensor_upper = sensor_upper + distanceToCrossing;
      sensed_lower = static_cast<int>(sensed_lower+distanceToCrossing) % 360;
      sensed_upper = static_cast<int>(sensed_upper+distanceToCrossing) % 360;
    }
    if ((sensed_lower < sensor_lower) && (sensed_upper > sensor_upper)) {
      return true;
    }
    if ((sensed_lower >= sensor_lower) && (sensed_lower <= sensor_upper)) {
      return true;
    }
    if ((sensed_upper >= sensor_lower) && (sensed_upper <= sensor_upper)) {
      return true;
    }
    return false;
  }

void SensorProximity::Reset() {
  distance_ = -1;
  point_of_detection_ = Position(0, 0);
  angle_of_detection_ = 0;
  activated(0);
} /* reset() */

NAMESPACE_END(csci3081);
