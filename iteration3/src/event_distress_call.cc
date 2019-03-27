/**
 * @file event_distress_call.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_distress_call.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructor
 ******************************************************************************/
EventDistressCall::EventDistressCall() :
    status_(false),
    point_of_distress_(0, 0) {
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void EventDistressCall::EmitMessage() const {
  printf("Distress call event at point %f %f.",
         point_of_distress_.x, point_of_distress_.y);
} /* EmitMessage() */

NAMESPACE_END(csci3081);
