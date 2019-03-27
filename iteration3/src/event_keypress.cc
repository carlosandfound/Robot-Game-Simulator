/**
 * @file event_keypress.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/event_keypress.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
enum event_commands EventKeypress::keypress_to_cmd(int key) const {
 /**
  * Currently only handles UP/DOWN/LEFT/RIGHT arrow keys.
  * Other keys are converted to COM_UNKNOWN.
  */
  switch (key) {
    case 263:return COM_TURN_LEFT;
    case 262:return COM_TURN_RIGHT;
    case 265:return COM_SPEED_UP;
    case 264:return COM_SLOW_DOWN;
    default:return COM_UNKNOWN;
  } /* switch() */
} /* keypress_to_cmd() */

NAMESPACE_END(csci3081);
