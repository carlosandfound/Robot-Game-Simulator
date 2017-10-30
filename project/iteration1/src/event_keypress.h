/**
 * @file event_keypress.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION1_SRC_EVENT_KEYPRESS_H_
#define PROJECT_ITERATION1_SRC_EVENT_KEYPRESS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "src/event_base_class.h"
#include "src/event_commands.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief An event representing that a key on the keyboard has been
 * pressed.
 *
 * They are sent from the graphics framework to the \ref GraphicsArenaViewer,
 * where they are interpreted further
 */
class EventKeypress : public EventBaseClass {
 public:
  explicit EventKeypress(int key) : key_(key) {}

  void EmitMessage(void) override { printf("Keypress command received\n"); }

  int getKey() {return key_;}

/**
 * @brief this method converts the key number to the appropriate command and
 * returns the command.
 */
  enum event_commands getCommand() { return keypress_to_cmd(key_); }

 private:
  enum event_commands keypress_to_cmd(int key);
  int key_;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION1_SRC_EVENT_KEYPRESS_H_ */
