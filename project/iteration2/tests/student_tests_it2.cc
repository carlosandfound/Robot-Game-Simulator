/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/arena.h"
#include "../src/sensor_touch.h"
#include "../src/position.h"
#include "../src/event_collision.h"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorTouch, Sanity) {
  EXPECT_EQ(1,1);
}

TEST(SensorTouch, GettersandSetters) {
  csci3081::SensorTouch st;

  EXPECT_EQ(st.activated(), 0);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));
  EXPECT_EQ(st.angle_of_contact(), 0.0);

  st.activated(1);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  st.angle_of_contact(45.0);
  EXPECT_EQ(st.activated(), 1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
  EXPECT_EQ(st.angle_of_contact(), 45.0);
}

TEST(SensorTouch,Reset) {
  csci3081::SensorTouch st;

  st.activated(1);
  st.point_of_contact(csci3081::Position(1.0, 1.0));
  st.angle_of_contact(45.0);
  EXPECT_EQ(st.activated(), 1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
  EXPECT_EQ(st.angle_of_contact(), 45.0);

  st.Reset();
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));
  EXPECT_EQ(st.activated(), 0);
}

TEST(SensorTouch,Accept) {
  csci3081::SensorTouch st;
  csci3081::EventCollision ec;

  st.Accept(&ec);
  EXPECT_EQ(st.activated(),1);
  EXPECT_EQ(st.angle_of_contact(), 0.0);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));

  ec.collided(true);
  ec.point_of_contact(csci3081::Position(10.0, 15.0));
  ec.angle_of_contact(50.0);
  st.Accept(&ec);
  EXPECT_EQ(st.activated(),1);
  EXPECT_EQ(st.point_of_contact(), csci3081::Position(10, 15));
  EXPECT_EQ(st.angle_of_contact(), 50.0);
}
