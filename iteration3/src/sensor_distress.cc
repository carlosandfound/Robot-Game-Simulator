/**
 * @file sensor_distress.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/sensor_distress.h"
#include <iostream>


/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

void SensorDistress::Accept(const EventDistressCall *const e) {
  // update status based on event reading
  if (e->get_distress_status()) {
    status_ = 1;
  } else {
    status_ = 0;
  }
}

void SensorDistress::Reset() {
  output(0);
} /* reset() */

NAMESPACE_END(csci3081);
