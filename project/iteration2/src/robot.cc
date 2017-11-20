/**
 * @file robot.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/robot.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Robot::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Robot::Robot(const struct robot_params *const params) :
    ArenaMobileEntity(params->radius, params->collision_delta,
                      params->pos, params->color),
    id_(-1),
    heading_angle_(0),
    angle_delta_(params->angle_delta),
    speed_delta_(params->speed_delta),
    battery_(params->battery_max_charge),
    motion_handler_(),
    motion_behavior_(),
    sensor_touch_(),
    initial_pos_(params->pos),
    entity_type_sensor_(new SensorEntityType(50)),
    distress_sensor_(new SensorDistress(100)),
    left_proximity_sensor_(new SensorProximity(100, 90)),
    right_proximity_sensor_(new SensorProximity(100, 90)) {
  motion_handler_.set_speed(5);
  motion_handler_.heading_angle(270);
  motion_handler_.max_speed(params->max_speed);
  motion_handler_.max_angle(360);
  motion_handler_.speed_delta(params->speed_delta);
  motion_handler_.angle_delta(params->angle_delta);
  id_ = next_id_++;
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Robot::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();
  // double old_heading_angle = heading_angle();

  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(left_proximity_sensor_);
  // Update the speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(distress_sensor_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);

  // double vel = std::sqrt(std::pow(get_pos().x() - old_pos.x(), 2) +
  //     std::pow(get_pos().y() - old_pos.y(), 2)) / static_cast<double>(dt);
  // double angular_vel = std::abs(heading_angle() - old_heading_angle) /
  //     static_cast<double>(dt);
  // battery_.Deplete(vel, angular_vel);

  battery_.Deplete(old_pos, get_pos(), static_cast<double>(dt));
} /* TimestepUpdate() */

void Robot::Accept(__unused const EventRecharge *const e) {
  battery_.EventRecharge();
}

void Robot::Accept(const EventCollision *const e) {
  sensor_touch_.Accept(e);
  battery_.Accept(e);
}

void Robot::Accept(const EventProximity *const e) {
  left_proximity_sensor_->Accept(e);
}

void Robot::Accept(const EventDistressCall *const e) {
  distress_sensor_->Accept(e);
}

/*
void Robot::Accept(const EventCommand *const e) {
  motion_handler_.AcceptCommand(e->cmd());
} // event_cmd()
*/


void Robot::Reset() {
  set_pos(initial_pos_);
  battery_.Reset();
  motion_handler_.Reset();
  motion_handler_.heading_angle(270);
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
  sensor_touch_.Reset();
  distress_sensor_->Reset();
} /* Reset() */

void Robot::ResetBattery() {
  battery_.Reset();
}

NAMESPACE_END(csci3081);
