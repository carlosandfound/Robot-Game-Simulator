/**
 * @file player.cc
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/player.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Static Variables
 ******************************************************************************/
uint Player::next_id_ = 0;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Player::Player(const struct robot_params *const params) :
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
    initial_pos_(params->pos) {
  set_frozen(false);
  set_unfreeze_time(0);
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
void Player::TimestepUpdate(uint dt) {
  Position old_pos = get_pos();

  // Update heading and speed as indicated by touch sensor
  motion_handler_.UpdateVelocity(sensor_touch_);
  // Use velocity and position to update position
  motion_behavior_.UpdatePosition(this, dt);
  // deplete battery based on position
  battery_.Deplete(old_pos, get_pos(), static_cast<double>(dt));
} /* TimestepUpdate() */

void Player::Accept(__unused const EventRecharge *const e) {
  battery_.EventRecharge();
}

void Player::Accept(__unused const EventCollision *const e) {
  sensor_touch_.Accept(e);
  battery_.Accept(e);
}

void Player::Accept(__unused const EventCommand *const e) {
  motion_handler_.AcceptCommand(e->cmd());
} /* event_cmd() */

void Player::Reset() {
  set_pos(initial_pos_);
  battery_.Reset();
  motion_handler_.Reset();
  motion_handler_.heading_angle(270);
  motion_handler_.set_speed(5);
  motion_handler_.max_speed(10);
  sensor_touch_.Reset();
  set_color(Color(0, 0, 255, 255));
  frozen_ = false;
  unfreeze_time_ = 0;
} /* Reset() */

void Player::ResetBattery() {
  battery_.Reset();
}

NAMESPACE_END(csci3081);
