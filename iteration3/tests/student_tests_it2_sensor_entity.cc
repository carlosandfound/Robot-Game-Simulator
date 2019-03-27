/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/sensor_entity_type.h"
/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorEntityType, Sanity) {
  EXPECT_EQ(1, 1);
}

TEST(SensorEntityType, Initialization) {
  csci3081::robot_params params;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 45);

  EXPECT_EQ(st.get_range(), 45);
  EXPECT_EQ(st.activated(), 0);
  EXPECT_EQ(st.output(),csci3081::NONE);
}

TEST(SensorEntityType, AcceptandGet) {
  csci3081::robot_params params;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 45);

  csci3081::EventTypeEmit em;
  em.set_id(0);
  em.set_entity_status(true);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KROBOT);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(1);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KSUPERBOT);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(2);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KPLAYER);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(3);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KHOMEBASE);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(4);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KRECHARGESTATION);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(5);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::KWALL);
  EXPECT_EQ(st.activated(), 1);

  em.set_id(10);
  st.Accept(&em);
  EXPECT_EQ(st.output(), csci3081::NONE);
  EXPECT_EQ(st.activated(), 1);
}

TEST(SensorEntityType, Reset) {
  csci3081::robot_params params;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 50);

  st.activated(1);
  EXPECT_EQ(st.get_range(), 50);
  EXPECT_EQ(st.activated(), 1);

  st.Reset();
  EXPECT_EQ(st.get_range(), 0);
  EXPECT_EQ(st.activated(), 0);
  EXPECT_EQ(st.output(), csci3081::NONE);

}
