/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/arena.h"
#include "../src/sensor_proximity.h"
#include "../src/position.h"
#include "../src/event_proximity.h"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorProximity, Sanity) {
  EXPECT_EQ(1,1);
}

TEST(SensorProximity, Test1) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,45);

  EXPECT_EQ(sp.get_range(), 45);
  EXPECT_EQ(sp.get_distance(), -1);
}

TEST(SensorProximity, Test2) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,50);
  EXPECT_EQ(sp.sensor_reading(&r1,&r1), 5);
  EXPECT_EQ(sp.in_range(0,0,0,0),true);
  EXPECT_EQ(sp.get_range(), 45);
  EXPECT_EQ(sp.get_distance(), 0);

  sp.Reset();
  EXPECT_EQ(sp.get_range(),0);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0, 0));
  EXPECT_EQ(sp.get_distance(), -1);
}

TEST(SensorProximity, Accept) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,100);
  EXPECT_EQ(sp.angle_of_detection(),0);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0,0));

  csci3081::EventProximity ep;
  ep.detected(true);
  ep.angle_of_detection(90);
  ep.point_of_detection(csci3081::Position(10,0));

  sp.Accept(&ep);

  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(10,0));
  EXPECT_EQ(sp.angle_of_detection(),90);
}
