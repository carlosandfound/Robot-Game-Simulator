/**
 * @file sensor_touch.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <limits>
#include "src/sensor_touch.h"
#include "src/arena_entity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
SensorTouch::SensorTouch(void) :
  activated_(false),
  point_of_contact_(0, 0),
  angle_of_contact_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

/*
 * @brief Accept collision event and determine if the sensor should be
 * activated or inactivated
 */
void SensorTouch::Accept(const EventCollision * const e) {
  if (e->collided()) {
    activated_ = true;
    point_of_contact_ = e->point_of_contact();
    angle_of_contact_ = e->angle_of_contact();
  } else {
    activated_ = false;
  }
}

void SensorTouch::Reset(void) {
  activated_ = false;
} /* reset() */

NAMESPACE_END(csci3081);
