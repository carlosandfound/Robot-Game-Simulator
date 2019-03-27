/**
 * @file event_collision.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_proximity.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventProximity::EventProximity() :
    detected_(false),
    point_of_detection_(0, 0),
    angle_of_detection_(0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventProximity::EmitMessage() const {
  printf("Detection event at point %f %f. Angle %f",
         point_of_detection_.x, point_of_detection_.y, angle_of_detection_);
} /* EmitMessage() */

NAMESPACE_END(csci3081);
