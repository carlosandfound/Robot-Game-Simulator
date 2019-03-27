/**
 * @file event_base_class.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_EVENT_BASE_CLASS_H_
#define PROJECT_ITERATION3_SRC_EVENT_BASE_CLASS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The base event class from which all events should inherit from.
 * As this is a base class, most of its methods are `virtual`
 */
class EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventBaseClass() = default;

  /**
   * @brief Default destructor.
   */
  virtual ~EventBaseClass() = default;

  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   */
  virtual void EmitMessage() const = 0;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION3_SRC_EVENT_BASE_CLASS_H_ */
