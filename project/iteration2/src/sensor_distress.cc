/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_distress.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorDistress::Accept(const EventDistressCall *const e) {
  // Determine if the sensor is activated or deactivated.
}

void SensorDistress::Reset() {
  range_ = 0;
  status_ = 0;
} /* reset() */

NAMESPACE_END(csci3081);
