/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/arena.h"
#include "../src/sensor_entity_type.h"
#include "../src/position.h"
#include "../src/event_type_emit.h"
#include "../src/entity_type.h"

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
TEST(SensorEntityType, Sanity) {
  EXPECT_EQ(1, 1);
}

TEST(SensorEntityType, Initialization) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 45);

  EXPECT_EQ(st.get_range(), 45);
  EXPECT_EQ(st.activated(), false);
  EXPECT_EQ(st.get_entity_type(),csci3081::NONE);
}

TEST(SensorEntityType, AcceptandGet) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 45);

  csci3081::EventTypeEmit em;
  em.set_id(0);
  em.set_entity_status(true);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KROBOT);
  EXPECT_EQ(st.activated(), true);

  em.set_id(1);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KSUPERBOT);

  em.set_id(2);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KPLAYER);

  em.set_id(3);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KHOMEBASE);

  em.set_id(4);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KRECHARGESTATION);

  em.set_id(5);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::KWALL);

  em.set_id(10);
  st.Accept(&em);
  EXPECT_EQ(st.get_entity_type(), csci3081::NONE);
}

TEST(SensorEntityType, Reset) {
  csci3081::robot_params params;
  params.pos = csci3081::Position(0, 0);
  params.angle_delta = 15;
  params.battery_max_charge = 100.;
  params.collision_delta = 0.1;
  params.radius = 5.0;
  csci3081::Robot r1 = csci3081::Robot(&params);
  csci3081::SensorEntityType st(&r1, 50);
  st.activated(1);

  EXPECT_EQ(st.get_range(), 50);
  EXPECT_EQ(st.activated(), 1);

  st.Reset();
  EXPECT_EQ(st.get_range(), 0);
  EXPECT_EQ(st.activated(), 0);

}
