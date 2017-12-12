/**
 * @file sensor_proximity.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_proximity.h"
#include <iostream>

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

/*
* Query refactor method that's used to replace the distanceToCrossing temp
* variable in In_Range()
*/
double SensorProximity::DistanceToCrossing() {
  return 360.0 - lower_sensor_;
}

bool SensorProximity::In_Range(double sensor_lower, double sensor_upper,
  double sensed_lower, double sensed_upper) {
    if (sensor_lower > sensor_upper) {
      lower_sensor_ = sensor_lower;
      sensor_lower = static_cast<int>(sensor_lower+DistanceToCrossing()) % 360;
      sensor_upper = sensor_upper + DistanceToCrossing();
      sensed_lower = static_cast<int>(sensed_lower+DistanceToCrossing()) % 360;
      sensed_upper = static_cast<int>(sensed_upper+DistanceToCrossing()) % 360;
    }
    if (sensed_lower > sensed_upper) {
      lower_sensor_ = sensed_lower;
      sensor_lower = static_cast<int>(sensor_lower+DistanceToCrossing()) % 360;
      sensor_upper = sensor_upper + DistanceToCrossing();
      sensed_lower = static_cast<int>(sensed_lower+DistanceToCrossing()) % 360;
      sensed_upper = static_cast<int>(sensed_upper+DistanceToCrossing()) % 360;
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
