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
  * -1 at a particular point of contact, which translates to an angle of
  * contact.
  */
class SensorProximity : public Sensor {
 public:
    /**
     * @brief Default constructor.
     */
    SensorProximity();

    /**
     * @brief compute the distance to the obstacle.
     *
     * @return If there isn't an obstacle, -1 is returned
     */
    double sensor_reading(class ArenaEntity *const ent1,
      class ArenaEntity *const ent2);

    /**
     * @brief check whether or not obstacle is in range of proximity sensor
     *
     * @return If obstacle is in range of the sensor, true is returned. Otherwise,
     * false is returned.
     */
    bool in_range(double sensor_lower, double sensor_upper,
      double sensed_lower, double sensed_upper);

 private:
    double range;
    double distance = -1;
};

NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_SENSOR_PROXIMITY_H_
