/**
 * @file sensor_base_class.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

#ifndef PROJECT_ITERATION1_SRC_SENSOR_BASE_CLASS_H_
#define PROJECT_ITERATION1_SRC_SENSOR_BASE_CLASS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The sensor class from which SensorTouch derives from.
 */
class SensorBaseClass {
 public:
  SensorBaseClass(void) {}
  virtual ~SensorBaseClass(void) {}
};

NAMESPACE_END(csci3081);

#endif /* PROJECT_ITERATION1_SRC_SENSOR_BASE_CLASS_H_ */
