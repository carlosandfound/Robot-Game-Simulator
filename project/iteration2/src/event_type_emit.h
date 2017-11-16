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
#include "src/entity_type.h"

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
class EventTypeEmit : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventTypeEmit();

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
    bool get_entity_status() const { return status_; }

    /**
     * @brief Setter method for entity type entity status.
     *
     * @param d The new entity type status.
     */
    void set_entity_status(bool e) { status_ = e; }

    /**
     * @brief Setter method for entity type id.
     *
     * @param d The new entity type id.
     */
    void set_id(bool i) { id_ = i; }

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

    /**
     * @brief getter method that returns the entity type of the robot generated
     * from the int id
     */
    enum entity_type get_entity_type() const { return entity_id_to_type(id_); }

 private:
   /**
    * @brief Convert robot's id values to entity type values.
    *
    * @param key An integer id value.
    *
    * @return The corresponding entity_type value.
    */
  enum entity_type entity_id_to_type(int id) const;
  bool status_;
  Position point_of_entity_;
  int id_ = -1;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION2_SRC_EVENT_TYPE_EMIT_H_ */
