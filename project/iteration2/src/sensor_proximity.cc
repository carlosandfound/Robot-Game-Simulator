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
}

double SensorProximity::sensor_reading(class ArenaEntity *const ent1,
  class ArenaEntity *const ent2) {
    return -1;
  }

bool SensorProximity::in_range(double sensor_lower, double sensor_upper,
  double sensed_lower, double sensed_upper) {
    return false;
  }

void SensorProximity::Reset() {
  range_ = 0;
  fov_ = 0;
  distance_ = -1;
  point_of_detection(Position(0, 0));
  angle_of_detection(0);
  activated(0);
} /* reset() */

NAMESPACE_END(csci3081);
