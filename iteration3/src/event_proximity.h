/**
 * @file event_proximity.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION3_SRC_EVENT_PROXIMITY_H_
#define PROJECT_ITERATION3_SRC_EVENT_PROXIMITY_H_

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
 * @brief A proximity event class, which is used after an entity is within a
 * specified distance of another entity in the Arena.
 */
class EventProximity : public EventBaseClass {
 public:
  /**
   * @brief Default constructor.
   */
  EventProximity();

    /**
     * @brief Each event, upon its firing/processing, should emit a message to
     * the user on `stdout` saying what happened, in order to
     * aid debugging.
     *
     * Reports the positions of the involved entities, point of detection
     * (in the field of view of the sensor) and the angle of detection
     * (relative to the robot).
     */
    void EmitMessage() const override;

    /**
     * @brief Getter method for proximity status.
     *
     * @return `true` when this instance represents an active detection
     * event. `false` when it represents a previous detection that has been
     * solved.
     */
    bool detected() const { return detected_; }

    /**
     * @brief Setter method for proximity status.
     *
     * @param d The new proximity status.
     */
    void detected(bool d) { detected_ = d; }

    /**
     * @brief Getter method for the point of detection.
     *
     * @return The point in the Arena at which the entities have detected each
     * other.
     */
    Position point_of_detection() const { return point_of_detection_; }

    /**
     * @brief Setter method for the point of detection.
     *
     * @param p The point in the Arena at which the entities have detected each
     * other.
     *
     * Should only be used by the class handling the proximity detection
     (that is, Arena).
     */
    void point_of_detection(Position p) { point_of_detection_ = p; }

    /**
     * @brief Getter method for the angle of detection.
     *
     * @return The angle, in degrees, as specified on the unit circle, that the
     * detection occurred at. Needed to calculate the bounce angle.
     */
    double angle_of_detection() const { return angle_of_detection_; }

    /**
     * @brief Setter method for the angle of detection.
     *
     * @param aod The angle, in degrees, as specified on the unit circle, that
     * the detection occurred at. Needed to calculate the bounce angle.
     *
     * Should only be used by the class handling proximity detection (that is,
     * Arena).
     */
    void angle_of_detection(double aod) { angle_of_detection_ = aod; }

 private:
    bool detected_;
    Position point_of_detection_;
    double angle_of_detection_;
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION3_SRC_EVENT_PROXIMITY_H_ */
