/**
 * @file event_proximity.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_
#define PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <cstdlib>
#include "src/event_base_class.h"
#include "src/position.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A distress call event class, which is used after an entity's distress
 * signal is detected within a specified distance in the Arena.
 */
class EventDistressCall : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventDistressCall();

    /**
     * @brief Each event, upon its firing/processing, should emit a message to
     * the user on `stdout` saying what happened, in order to
     * aid debugging.
     *
     * Reports the positions of the entity that registers the distres call
     */
    void EmitMessage() const override;

    /**
     * @brief Getter method for distress call status.
     *
     * @return true when this instance represents a distress call.
     * false when it represents a previous distress call that was solved.
     */
    bool get_distress_status() const { return status_; }

    /**
     * @brief Setter method for distress call status.
     *
     * @param d The new distress status.
     */
    void set_distress_status(bool d) { status_ = d; }

    /**
     * @brief Getter method for the point of distress call.
     *
     * @return The point in the Arena at which the distress signal has been
     * registered
     */
    Position point_of_distress() const { return point_of_distress_; }

    /**
     * @brief Setter method for the point of distress call.
     *
     * @param p The point in the Arena at which the distress call occurs
     *
     * Should only be used by the class handling the proximity detection
     (that is, Arena).
     */
    void point_of_distress(Position p) { point_of_distress_ = p; }

 private:
    bool status_;
    Position point_of_distress_;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION2_SRC_EVENT_DISTRESS_CALL_H_ */
