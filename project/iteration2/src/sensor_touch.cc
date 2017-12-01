/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_touch.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch() :
    Sensor(),
    activated_(0),
    point_of_contact_(0, 0),
    angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorTouch::Accept(const EventCollision *const e) {
  // Determine if the sensor needs to be activated or deactivated.
  if (e->collided()) {
    activated(1);
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    activated(0);
  }
}

void SensorTouch::Reset() {
  activated(0);
  point_of_contact(Position(0, 0));
  angle_of_contact(0);
} /* reset() */

NAMESPACE_END(csci3081);
