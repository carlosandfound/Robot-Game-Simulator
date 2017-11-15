/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/arena.h"
#include "../src/sensor_distress.h"
#include "../src/position.h"
#include "../src/event_distress_call.h"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorDistress, Sanity) {
  EXPECT_EQ(1, 1);
}

TEST(SensorDistress, Test1) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorDistress sd(&r1, 45);

  EXPECT_EQ(sd.get_range(), 45);
  EXPECT_EQ(sd.output(), 0);

  csci3081::EventDistressCall ed;
  sd.Accept(&ed);
  EXPECT_EQ(sd.output(), 0);

  ed.set_distress_status(true);
  ed.point_of_distress(csci3081::Position(10, 0));

  sd.Accept(&ed);
  EXPECT_EQ(sd.output(), 1);

  sd.Reset();
  EXPECT_EQ(sd.get_range(), 0);
  EXPECT_EQ(sd.output(), 0);
}
