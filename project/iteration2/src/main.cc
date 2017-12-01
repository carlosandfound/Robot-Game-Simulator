/**
 * @file main.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"

/*******************************************************************************
 * Constants
 ******************************************************************************/
static const uint X_DIM_ = 1024;
static const uint Y_DIM_ = 768;
static const int MIN_OBSTACLE_RADIUS_ = 10;
static const int MAX_OBSTACLE_RADIUS_ = 50;

/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int, char **) {
  // Essential call to initiate the graphics window
  csci3081::InitGraphics();

  // Initialize default properties for various arena entities
  /*
  defulat values for robot params are the following:
        rparams.battery_max_charge = 100.0;
        rparams.angle_delta = 10;
        rparams.speed_delta = 1;
        rparams.max_speed = 10;
        rparams.collision_delta = 1;
        rparams.radius = 20.0;
        rparams.pos = csci3081::Position(0, 0);
        rparams.color = csci3081::Color(200, 100, 0, 0); // orange
  */

  csci3081::robot_params rparams;
  rparams.pos = csci3081::Position(500, 500);
  rparams.color = csci3081::Color(0, 0, 255, 255);  // blue

  csci3081::robot_params rparams1;
  rparams1.pos = csci3081::Position(100, 600);
  rparams1.color = csci3081::Color(0, 200, 0, 200);  // bright green

  csci3081::robot_params rparams2;
  rparams2.pos = csci3081::Position(100, 100);
  rparams2.color = csci3081::Color(0, 200, 0, 200);  // bright green

  csci3081::robot_params rparams3;
  rparams3.pos = csci3081::Position(600, 100);
  rparams3.color = csci3081::Color(0, 200, 0, 200);  // bright green

  csci3081::robot_params rparams4;
  rparams4.pos = csci3081::Position(900, 600);
  rparams4.color = csci3081::Color(0, 200, 0, 200);  // bright green

  csci3081::robot_params rparams5;
  rparams5.pos = csci3081::Position(900, 100);
  rparams5.color = csci3081::Color(0, 200, 0, 200);  // bright green

  csci3081::arena_params aparams;

  aparams.n_obstacles = 5;
  aparams.x_dim = X_DIM_;
  aparams.y_dim = Y_DIM_;

  aparams.robot = rparams;
  aparams.robots[0] = rparams1;
  aparams.robots[1] = rparams2;
  aparams.robots[2] = rparams3;
  aparams.robots[3] = rparams4;
  aparams.robots[4] = rparams5;

  aparams.recharge_station.radius = 20.0;
  aparams.recharge_station.pos = {500, 300};
  aparams.recharge_station.color =
      csci3081::Color(0, 128, 128, 255); /* green */

  aparams.home_base.radius = 20.0;
  aparams.home_base.collision_delta = 1;
  aparams.home_base.pos = {400, 400};
  aparams.home_base.color = csci3081::Color(255, 0, 0, 255);  // red

  aparams.obstacles[0].radius = 10.0;
  aparams.obstacles[0].pos = {300, 600};
  aparams.obstacles[0].color = csci3081::Color(255, 255, 255, 255); /* white */

  aparams.obstacles[1].radius = 10.0;
  aparams.obstacles[1].pos = {300, 300};
  aparams.obstacles[1].color = csci3081::Color(255, 255, 255, 255);

  aparams.obstacles[2].radius = 10.0;
  aparams.obstacles[2].pos = {300, 100};
  aparams.obstacles[2].color = csci3081::Color(255, 255, 255, 255);

  aparams.obstacles[3].radius = 10.0;
  aparams.obstacles[3].pos = {700, 100};
  aparams.obstacles[3].color = csci3081::Color(255, 255, 255, 255);

  aparams.obstacles[4].radius = 10.0;
  aparams.obstacles[4].pos = {700, 600};
  aparams.obstacles[4].color = csci3081::Color(255, 255, 255, 255);

  // Start up the graphics (which creates the arena).
  // Run() will enter the nanogui::mainloop().
  auto *app = new csci3081::GraphicsArenaViewer(&aparams);
  app->Run();
  csci3081::ShutdownGraphics();
  return 0;
}
