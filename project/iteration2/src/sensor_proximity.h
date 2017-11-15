/**
 * @file sensor_proximity.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION2_SRC_SENSOR_PROXIMITY_H_
#define PROJECT_ITERATION2_SRC_SENSOR_PROXIMITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"
#include "src/sensor.h"
#include "src/event_proximity.h"
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Classes
 ******************************************************************************/
 /**
  * @brief Class representing a proximity sensor.
  *
  * proximity sensors have a range and field of view where it can sense onjects.
  * A single cone emanating from the center of the robot, split in two,
  * signifies the two fields of view for the two sensors. The range and field
  * of view, expressed as an angle, are attributes of the sensor. Sensor output
  * is the distance to an obstacle. If there is no obstacle, it should output
  * -1 at a particular point of detection, which translates to an angle of
  * detection.
  */
class SensorProximity : public Sensor {
 public:
    /**
     * @brief constructor with sensor's robot user and field of view (fov) as
     * parameters.
     */
    //  SensorProximity();
    SensorProximity(const Robot * robot, double range):
    robot_(robot),
    range_(range),
    point_of_detection_(0, 0),
    angle_of_detection_(0) {
    }

    /**
     * @brief Compute a new reading based on a proximity event.
     *
     * used sensor_reading() and in_range() to compute distance between
     * robot being sensed and robot with proximity sensor.
     */
    void Accept(const EventProximity *const e);

    /**
     * @brief compute the distance between sensor robot and entity being sensed.
     *
     * @return If there isn't an obstacle in fov, -1 is returned
     */
    double sensor_reading(class ArenaEntity *const ent1,
      class ArenaEntity *const ent2);

    /**
     * @brief check whether or not sensed entity is in range of proximity sensor
     *
     * @return If sensed entity is in range of the sensor, true is returned.
     * Otherwise, false is returned.
     */
    bool in_range(double sensor_lower, double sensor_upper,
      double sensed_lower, double sensed_upper);

    /**
     * @brief return the distance from the robot to the entity being sensed.
     *
     * @return If no robot is sensed by sensor, output is -1.
     */
    double get_distance() { return distance_; }

    /**
     * @brief method that returns the range/fov of the proximity sensor
     */
    int get_range() { return range_; }

    /**
     * @brief Getter method for the point of detection.
     *
     * Should only be called when the sensor is activated.
     *
     * @return The latest point of detection.
     */
    Position point_of_detection() { return point_of_detection_; }

    /**
     * @brief Setter method for the point of detection.
     *
     * @param p The new point of detection.
     */
    void point_of_detection(Position p) {
      point_of_detection_ = p;
    }

    /**
     * @brief Getter method for the angle of detection.
     *
     * Should only be called when the sensor is activated.
     *
     * @return The latest angle of detection.
     */
    double angle_of_detection() { return angle_of_detection_; }

    /**
     * @brief Setter method for the angle of detection.
     *
     * @param aoc The new angle of detection.
     */
    void angle_of_detection(double aoc) { angle_of_detection_ = aoc; }

    void Reset() override;

 private:
    const Robot * robot_;
    double range_;
    double distance_ = -1;
    Position point_of_detection_;
    double angle_of_detection_;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SENSOR_PROXIMITY_H_
