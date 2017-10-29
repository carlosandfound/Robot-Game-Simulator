/**
 * @file sensor_base_class.h
 */

#ifndef SRC_SENSOR_BASE_CLASS_H_
#define SRC_SENSOR_BASE_CLASS_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

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

  /**
   * @brief Each event, upon its firing, should emit a message to the user on
   * stdout saying what happened, in order to aid debugging.
   *
   */
  //virtual void EmitMessage(void) = 0;
};

NAMESPACE_END(csci3081);

#endif /* SRC_SENSOR_BASE_CLASS_H_ */
