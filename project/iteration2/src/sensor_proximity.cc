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

double SensorProximity::sensor_reading(class ArenaEntity *const ent1,
  class ArenaEntity *const ent2) {
    return -1;
  }

bool SensorProximity::in_range(double sensor_lower, double sensor_upper,
  double sensed_lower, double sensed_upper) {
    if (sensor_lower > sensor_upper) {
      double tmp = sensor_lower;
      sensor_lower = sensor_upper;
      sensor_upper = tmp;
    }
    if (sensed_lower > sensed_upper) {
      sensor_lower = sensed_upper;
      sensor_upper = sensed_lower;
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
  point_of_detection(Position(0, 0));
  angle_of_detection(0);
  activated(0);
} /* reset() */

NAMESPACE_END(csci3081);
