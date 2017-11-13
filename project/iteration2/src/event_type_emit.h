/**
 * @file event_type_entity.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_EVENT_TYPE_EMIT_H_
#define PROJECT_ITERATION2_SRC_EVENT_TYPE_EMIT_H_

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
 * @brief An entity type event class, which is used after an entity at a
 * specified distance is detected by the sensor.
 */
class EventTypeEntity : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventTypeEntity();

    /**
     * @brief Each event, upon its firing/processing, should emit a message to
     * the user on `stdout` saying what happened, in order to
     * aid debugging.
     *
     * Reports the positions of the involved entities and the type of entiy
     * detected
     */
    void EmitMessage() const override;

    /**
     * @brief Getter method for entity status.
     *
     * @return `true` when this instance represents an active entity
     * event. `false` when it represents a previous entity that has been
     * solved.
     */
    bool get_entity() const { return entity_; }

    /**
     * @brief Setter method for entity type entity status.
     *
     * @param d The new entity type status.
     */
    void set_entity(bool e) { entity_ = e; }

    /**
     * @brief Getter method for the point of entity type.
     *
     * @return The point in the Arena at which the entity type has been
     * detected.
     */
    Position point_of_entity() const { return point_of_entity_; }

    /**
     * @brief Setter method for the point of entity type.
     *
     * @param p The point in the Arena at which the entity type has been
     * detected.
     *
     * Should only be used by the class handling the entity type entity
     * (that is, Arena).
     */
    void point_of_entity(Position p) { point_of_entity_ = p; }

 private:
    bool entity_;
    Position point_of_entity_;
    double angle_of_entity_;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION2_SRC_EVENT_TYPE_EMIT_H_ */
