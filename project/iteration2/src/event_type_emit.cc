/**
 * @file event_type_emit.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_type_emit.h"
#include "src/entity_type.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
EventTypeEmit::EventTypeEmit() :
     status_(false),
     point_of_entity_(0, 0) {
}

 /*******************************************************************************
  * Member Functions
  ******************************************************************************/
void EventTypeEmit::EmitMessage() const {
  printf("Entity type signal event at point %f %f.",
          point_of_entity_.x, point_of_entity_.y);
} /* EmitMessage() */

enum entity_type EventTypeEmit::entity_id_to_type(int id) const {
  switch (id) {
     case 0:return KROBOT;
     case 1:return KSUPERBOT;
     case 2:return KPLAYER;
     case 3:return KHOMEBASE;
     case 4:return KRECHARGESTATION;
     case 5:return KWALL;
     default:return NONE;
  } /* switch() */
}

NAMESPACE_END(csci3081);
