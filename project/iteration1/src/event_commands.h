/**
 * @file event_commands.h
 *
 * @copyright 2017 John Harwell, All rights reserved.
 *
 */

#ifndef PROJECT_ITERATION1_SRC_EVENT_COMMANDS_H_
#define PROJECT_ITERATION1_SRC_EVENT_COMMANDS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief The supported commands that the robot supports: speed up, slow down
 * turn left a little bit, turn right a little bit. Doesn't get much simpler
 * than that!
 */
enum event_commands {
  COM_TURN_LEFT,
  COM_TURN_RIGHT,
  COM_SPEED_UP,
  COM_SLOW_DOWN
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION1_SRC_EVENT_COMMANDS_H_ */
