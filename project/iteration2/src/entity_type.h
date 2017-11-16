/**
 * @file event_type.h
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 *
 */

#ifndef PROJECT_ITERATION2_SRC_ENTITY_TYPE_H_
#define PROJECT_ITERATION2_SRC_ENTITY_TYPE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/common.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Type Definitions
 ******************************************************************************/
/**
 * @brief The commands that describe the type of the entities: robot, superbot,
 * player, homebase, recharge station, wall
 */
enum entity_type {
  KROBOT,
  KSUPERBOT,
  KPLAYER,
  KHOMEBASE,
  KRECHARGESTATION,
  KWALL,
  NONE
};
NAMESPACE_END(csci3081);

#endif  // PROJECT_ITERATION2_SRC_ENTITY_TYPE_H_
