/**
 * @file graphics_arena_viewer.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "src/graphics_arena_viewer.h"
#include "src/arena_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constants
 ******************************************************************************/
// constants for adding the extra game stats menu to the GUI
const int GUI_MENU_WIDTH = 180;
const int GUI_MENU_GAP = 10;

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
GraphicsArenaViewer::GraphicsArenaViewer(
    const struct arena_params *const params) :
    csci3081::GraphicsApp(
        params->x_dim + GUI_MENU_WIDTH + GUI_MENU_GAP * 2,
        params->y_dim,
        "Player Simulation"),
    arena_(new Arena(params)),
    paused_(false),
    pause_btn_(nullptr),
    last_dt(0) {
  auto *gui = new nanogui::FormHelper(this);
  nanogui::ref<nanogui::Window> window =
      gui->addWindow(
          Eigen::Vector2i(params->x_dim + GUI_MENU_GAP, 10),
          "Menu");

  gui->addGroup("Simulation Control");
  gui->addButton("Restart",
                 std::bind(&GraphicsArenaViewer::OnRestartBtnPressed, this));
  pause_btn_ = gui->addButton("Pause",
                              std::bind(&GraphicsArenaViewer::OnPauseBtnPressed,
                                        this));

  gui->addGroup("Game Stats");
  win_ = new nanogui::IntBox<int>(window);
  lose_ = new nanogui::IntBox<int>(window);
  win_->setFixedWidth(50);
  lose_->setFixedWidth(50);
  win_->setEditable(false);
  lose_->setEditable(false);
  win_->setAlignment(nanogui::TextBox::Alignment::Center);
  lose_->setAlignment(nanogui::TextBox::Alignment::Center);
  gui->addWidget("Win", win_);
  gui->addWidget("Lose", lose_);

  gui->addGroup("Entity Stats");
  // player_battery_ = new nanogui::ProgressBar(window);
  // player_battery_->setFixedWidth(50);
  // player_battery_->setValue(1);
  // gui->addWidget("Robot Battery", player_battery_);
  player_pos_x_ = new nanogui::IntBox<int>(window);
  player_pos_y_ = new nanogui::IntBox<int>(window);
  player_speed_ = new nanogui::IntBox<int>(window);
  player_angle_ = new nanogui::IntBox<int>(window);
  player_battery_text_ = new nanogui::IntBox<int>(window);
  home_pos_x_ = new nanogui::IntBox<int>(window);
  home_pos_y_ = new nanogui::IntBox<int>(window);
  home_speed_ = new nanogui::IntBox<int>(window);
  home_angle_ = new nanogui::IntBox<int>(window);
  player_pos_x_->setFixedWidth(50);
  player_pos_y_->setFixedWidth(50);
  player_speed_->setFixedWidth(50);
  player_angle_->setFixedWidth(50);
  player_battery_text_->setFixedWidth(50);
  home_pos_x_->setFixedWidth(50);
  home_pos_y_->setFixedWidth(50);
  home_speed_->setFixedWidth(50);
  home_angle_->setFixedWidth(50);
  player_pos_x_->setEditable(false);
  player_pos_y_->setEditable(false);
  player_speed_->setEditable(false);
  player_angle_->setEditable(false);
  player_battery_text_->setEditable(false);
  home_pos_x_->setEditable(false);
  home_pos_y_->setEditable(false);
  home_speed_->setEditable(false);
  home_angle_->setEditable(false);
  player_pos_x_->setAlignment(nanogui::TextBox::Alignment::Center);
  player_pos_y_->setAlignment(nanogui::TextBox::Alignment::Center);
  player_speed_->setAlignment(nanogui::TextBox::Alignment::Center);
  player_angle_->setAlignment(nanogui::TextBox::Alignment::Center);
  player_battery_text_->setAlignment(nanogui::TextBox::Alignment::Center);
  home_pos_x_->setAlignment(nanogui::TextBox::Alignment::Center);
  home_pos_y_->setAlignment(nanogui::TextBox::Alignment::Center);
  home_speed_->setAlignment(nanogui::TextBox::Alignment::Center);
  home_angle_->setAlignment(nanogui::TextBox::Alignment::Center);
  gui->addWidget("Player.x", player_pos_x_);
  gui->addWidget("Player.y", player_pos_y_);
  gui->addWidget("Player.speed", player_speed_);
  gui->addWidget("Player.angle", player_angle_);
  gui->addWidget("Player.battery", player_battery_text_);
  gui->addWidget("HomeBase.x", home_pos_x_);
  gui->addWidget("HomeBase.y", home_pos_y_);
  gui->addWidget("HomeBase.speed", home_speed_);
  gui->addWidget("HomeBase.angle", home_angle_);

  performLayout();
}

/*******************************************************************************
 * Member Functions
 ******************************************************************************/

// This is the primary driver for state change in the arena.
// It will be called at each iteration of nanogui::mainloop()
void GraphicsArenaViewer::UpdateSimulation(double dt) {
  if (!paused_) {
    if ((last_dt + dt) <= .05) {
      last_dt += dt;
      return;
    }

    last_dt = 0;
    arena_->AdvanceTime(dt);
    win_->setValue(arena_->win());
    lose_->setValue(arena_->lose());
    // use IntBox and static_cast for these stats
    // because double values take up too much space on the GUI
    player_pos_x_->setValue(
        static_cast<int>(arena_->player()->get_pos().x));
    player_pos_y_->setValue(
        static_cast<int>(arena_->player()->get_pos().y));
    player_speed_->setValue(
        static_cast<int>(arena_->player()->get_speed()));
    player_angle_->setValue(
        static_cast<int>(arena_->player()->get_heading_angle()));
    player_battery_text_->setValue(
        static_cast<int>(arena_->player()->get_battery_level()));
    home_pos_x_->setValue(
        static_cast<int>(arena_->home_base()->get_pos().x));
    home_pos_y_->setValue(
        static_cast<int>(arena_->home_base()->get_pos().y));
    home_speed_->setValue(
        static_cast<int>(arena_->home_base()->get_speed()));
    home_angle_->setValue(
        static_cast<int>(arena_->home_base()->get_heading_angle()));
    // player_battery_->setValue(
      //  static_cast<float>(
        //    arena_->robot()->battery_level() /
          //      arena_->robot()->max_battery_level()));
  }
}

/*******************************************************************************
 * Handlers for User Keyboard and Mouse Events
 ******************************************************************************/
void GraphicsArenaViewer::OnRestartBtnPressed() {
  arena_->Reset();
}

void GraphicsArenaViewer::OnPauseBtnPressed() {
  paused_ = !paused_;
  if (paused_) {
    pause_btn_->setCaption("Play");
  } else {
    pause_btn_->setCaption("Pause");
  }
}

void GraphicsArenaViewer::OnMouseMove(__unused int x, __unused int y) {
}

void GraphicsArenaViewer::OnLeftMouseDown(__unused int x, __unused int y) {
}

void GraphicsArenaViewer::OnLeftMouseUp(__unused int x, __unused int y) {
}

void GraphicsArenaViewer::OnRightMouseDown(__unused int x, __unused int y) {
}

void GraphicsArenaViewer::OnRightMouseUp(__unused int x, __unused int y) {
}

void GraphicsArenaViewer::OnKeyDown(__unused const char *c,
                                    __unused int modifiers) {
}

void GraphicsArenaViewer::OnKeyUp(__unused const char *c,
                                  __unused int modifiers) {
}

void GraphicsArenaViewer::OnSpecialKeyDown(int key,
                                           __unused int scancode,
                                           __unused int modifiers) {
  EventKeypress e(key);
  arena_->Accept(&e);
}

void GraphicsArenaViewer::OnSpecialKeyUp(__unused int key,
                                         __unused int scancode,
                                         __unused int modifiers) {
}

/*******************************************************************************
 * Drawing of Entities in Arena
 ******************************************************************************/
void GraphicsArenaViewer::DrawPlayer(NVGcontext *ctx,
  const Player *const player) {
  // translate and rotate all graphics calls that follow so that they are
  // centered, at the position and heading of this robot
  nvgSave(ctx);
  nvgTranslate(ctx,
               static_cast<float>(player->get_pos().x),
               static_cast<float>(player->get_pos().y));
  nvgRotate(ctx,
            static_cast<float>(player->get_heading_angle() * M_PI / 180.0));

  // robot's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, static_cast<float>(player->radius()));
  nvgFillColor(ctx,
               nvgRGBA(player->get_color().r, player->get_color().g,
                       player->get_color().b, player->get_color().a));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // robot id text label
  nvgSave(ctx);
  nvgRotate(ctx, static_cast<float>(M_PI / 2.0));
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, 0.0, 10.0, player->get_name().c_str(), nullptr);
  nvgRestore(ctx);
  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawRobot(NVGcontext *ctx,
  const Robot *const robot) {
  // translate and rotate all graphics calls that follow so that they are
  // centered, at the position and heading of this robot
  nvgSave(ctx);
  nvgTranslate(ctx,
               static_cast<float>(robot->get_pos().x),
               static_cast<float>(robot->get_pos().y));
  nvgRotate(ctx,
            static_cast<float>(robot->get_heading_angle() * M_PI / 180.0));

  // robot's circle
  nvgBeginPath(ctx);
  nvgCircle(ctx, 0.0, 0.0, static_cast<float>(robot->radius()));
  nvgFillColor(ctx,
               nvgRGBA(robot->get_color().r, robot->get_color().g,
                       robot->get_color().b, robot->get_color().a));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  // robot id text label
  nvgSave(ctx);
  nvgRotate(ctx, static_cast<float>(M_PI / 2.0));
  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx, 0.0, 10.0, robot->get_name().c_str(), nullptr);
  nvgRestore(ctx);
  nvgRestore(ctx);
}

void GraphicsArenaViewer::DrawObstacle(NVGcontext *ctx,
                                       const Obstacle *const obstacle) {
  nvgBeginPath(ctx);
  nvgCircle(ctx,
            static_cast<float>(obstacle->get_pos().x),
            static_cast<float>(obstacle->get_pos().y),
            static_cast<float>(obstacle->radius()));
  nvgFillColor(ctx,
               nvgRGBA(obstacle->get_color().r, obstacle->get_color().g,
                       obstacle->get_color().b, obstacle->get_color().a));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx,
          static_cast<float>(obstacle->get_pos().x),
          static_cast<float>(obstacle->get_pos().y),
          obstacle->get_name().c_str(), nullptr);
}

/**
 * @todo: rotate HomeBase too?
 */
void GraphicsArenaViewer::DrawHomeBase(NVGcontext *ctx,
                                       const HomeBase *const home) {
  nvgBeginPath(ctx);
  nvgCircle(ctx,
            static_cast<float>(home->get_pos().x),
            static_cast<float>(home->get_pos().y),
            static_cast<float>(home->radius()));
  nvgFillColor(ctx,
               nvgRGBA(home->get_color().r, home->get_color().g,
                       home->get_color().b, home->get_color().a));
  nvgFill(ctx);
  nvgStrokeColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgStroke(ctx);

  nvgFillColor(ctx, nvgRGBA(0, 0, 0, 255));
  nvgText(ctx,
          static_cast<float>(home->get_pos().x),
          static_cast<float>(home->get_pos().y),
          home->get_name().c_str(),
          nullptr);
}

void GraphicsArenaViewer::DrawUsingNanoVG(NVGcontext *ctx) {
  // initialize text rendering settings
  nvgFontSize(ctx, 18.0f);
  nvgFontFace(ctx, "sans-bold");
  nvgTextAlign(ctx, NVG_ALIGN_CENTER | NVG_ALIGN_MIDDLE);

  std::vector<Obstacle *> obstacles = arena_->obstacles();
  for (auto &obstacle : obstacles) {
    DrawObstacle(ctx, obstacle);
  } /* for(i..) */

  DrawPlayer(ctx, arena_->player());
  DrawHomeBase(ctx, arena_->home_base());
  DrawRobot(ctx, arena_->robot1());
  DrawRobot(ctx, arena_->robot2());
  DrawRobot(ctx, arena_->robot3());
  DrawRobot(ctx, arena_->robot4());
  DrawRobot(ctx, arena_->robot5());

  //if (arena_ -> superbot_present() == true) {
    //DrawRobot(ctx, arena_-> superbot());
    //arena_->superbot_present(false);
  //}
}

NAMESPACE_END(csci3081);
