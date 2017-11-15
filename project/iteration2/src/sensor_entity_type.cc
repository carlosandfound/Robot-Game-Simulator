/**
 * @file sensor_entity_type.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorEntityType::Accept(const EventTypeEmit *const e) {
  // Determine if the sensor is activated or deactivated.
}

void SensorEntityType::Reset() {
  range_ = 0;
  activated(0);
} /* reset() */

NAMESPACE_END(csci3081);
