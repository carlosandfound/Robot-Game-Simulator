/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/sensor_proximity.h"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorProximity, Sanity) {
  EXPECT_EQ(1,1);
}

TEST(SensorProximity, Initialization) {
  csci3081::robot_params params;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,45,50);

  EXPECT_EQ(sp.get_range(), 45);
  EXPECT_EQ(sp.get_distance(), -1);
  EXPECT_EQ(sp.get_fov(), 50);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0,0));
  EXPECT_EQ(sp.angle_of_detection(),0);
  EXPECT_EQ(sp.activated(), 0);
}

TEST(SensorProximity, GettersandSetters) {
  csci3081::robot_params params;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,45,50);

  EXPECT_EQ(sp.get_range(), 45);
  EXPECT_EQ(sp.get_distance(), -1);
  EXPECT_EQ(sp.get_fov(), 50);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0,0));
  EXPECT_EQ(sp.angle_of_detection(),0);
  EXPECT_EQ(sp.activated(), 0);

  sp.set_range(-45);
  sp.set_fov(-50);
  sp.point_of_detection(csci3081::Position(10,10));
  sp.angle_of_detection(100);
  sp.activated(1);
  EXPECT_EQ(sp.get_range(), -45);
  EXPECT_EQ(sp.get_fov(), -50);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(10,10));
  EXPECT_EQ(sp.angle_of_detection(),100);
  EXPECT_EQ(sp.activated(), 1);

  sp.Reset();
  EXPECT_EQ(sp.get_range(),0);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0, 0));
  EXPECT_EQ(sp.get_distance(), -1);
  EXPECT_EQ(sp.activated(), 0);
}

TEST(SensorProximity, sensor_reading_and_in_range) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,0,0);
  EXPECT_EQ(sp.sensor_reading(&r1,&r1), 5);
  EXPECT_EQ(sp.in_range(0,0,0,0),true);
  EXPECT_EQ(sp.get_range(), 45);
  EXPECT_EQ(sp.get_distance(), 0);
  EXPECT_EQ(sp.activated(), 1);

  csci3081::robot_params params2;
  params2.pos = csci3081::Position(0, 10);
  params2.angle_delta = 15;
  params2.battery_max_charge = 100.;
  params2.collision_delta = 0.1;
  params2.radius = 5.0;
  csci3081::Robot r2 = csci3081::Robot(&params2);
  csci3081::SensorProximity sp2(&r1,5,5);
  EXPECT_EQ(sp2.sensor_reading(&r1,&r2), 10);
  EXPECT_EQ(sp2.in_range(5,10,0,10),true);
  EXPECT_EQ(sp2.get_range(), 5);
  EXPECT_EQ(sp2.get_distance(), 10);
  EXPECT_EQ(sp2.activated(), 1);

  csci3081::robot_params params3;
  params3.pos = csci3081::Position(500, 500);
  params3.angle_delta = 15;
  params3.battery_max_charge = 100.;
  params3.collision_delta = 0.1;
  params3.radius = 5.0;
  csci3081::Robot r3 = csci3081::Robot(&params3);
  csci3081::SensorProximity sp3(&r1,10,10);
  EXPECT_EQ(sp3.sensor_reading(&r1,&r3), -1);
  EXPECT_EQ(sp3.in_range(0,0,0,0),false);
  EXPECT_EQ(sp3.get_range(), 10);
  EXPECT_EQ(sp3.get_distance(), -1);
  EXPECT_EQ(sp3.activated(), 0);
}

TEST(SensorProximity, Accept) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorProximity sp(&r1,0,0);

  csci3081::EventProximity ep;

  sp.Accept(&ep);
  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(0,0));
  EXPECT_EQ(sp.angle_of_detection(),0);
  EXPECT_EQ(sp.activated(),0);

  ep.detected(true);
  ep.angle_of_detection(90);
  ep.point_of_detection(csci3081::Position(10,0));

  EXPECT_EQ(sp.point_of_detection(),csci3081::Position(10,0));
  EXPECT_EQ(sp.angle_of_detection(),90);
  EXPECT_EQ(sp.get_distance(), 0);
  EXPECT_EQ(sp.activated(), 1);
}
