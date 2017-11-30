/**
 * @file event_base_class.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_BASE_CLASS_H_
#define PROJECT_ITERATION2_SRC_EVENT_BASE_CLASS_H_

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

 /*struct CollisionEntity {
   ArenaEntity * a1;
   ArenaEntity * a2;
 }*/
/**
 * @brief The base event class from which all events should inherit from.
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

  /*
  double angle_of_contact() const { return angle_of_contact_; }
  Position point_of_contact() const { return point_of_contact_; }
  void point_of_contact(Position p) { point_of_contact_ = p; }
  void angle_of_contact(double aoc) { angle_of_contact_ = aoc; }
  */


  /**
   * @brief Each event, upon its firing/processing, should emit a message to
   * the user on `stdout` saying what happened, in order to
   * aid debugging.
   */
  virtual void EmitMessage() const = 0;

 /*private:
   Position point_of_contact_;
  double angle_of_contact_;*/
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION2_SRC_EVENT_BASE_CLASS_H_ */
