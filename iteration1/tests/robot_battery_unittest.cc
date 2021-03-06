/* STUDENTS:  DO NOT EDIT THIS FILE.  INSTEAD, MODIFY YOUR OWN PROJECT
 * CODE TO FIT THE SPECIFICATION GIVEN BY THE TESTS IN THIS FILE.
 *
 * If you DO modify it, we overwrite it with a fresh version from our repo
 * when grading, so you can't use it to fudge the tests anyway.
 *
 * This file is used by the CS3081W auto-grading system.
 *
 * Please note, the assessment tests for grading, will use the same include
 * files, class names, and function names for accessing students' code that you
 * find in this file.  So students, if you write your code so that it passes
 * these feedback tests, you can be assured that the auto-grader will at least
 * be able to properly link with your code.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>
#include "../src/robot_battery.h"
#include "../src/robot.h"

/*******************************************************************************
 * Constant Definitions
 ******************************************************************************/
#define MAX_LEVEL 100.0

/*******************************************************************************
 * Test Cases
 ******************************************************************************/
#ifdef PRIORITY1_TESTS

// Verify getters/setters
TEST(RobotBattery, Sanity) {
  csci3081::RobotBattery bat(MAX_LEVEL);
  EXPECT_DOUBLE_EQ(bat.level(), MAX_LEVEL);
}

// Verify RobotBattery reset works properly
TEST(RobotBattery, Reset) {
  csci3081::RobotBattery bat(MAX_LEVEL);
  bat.Deplete(Position(0, 0), Position(1, 1), 1);
  bat.Reset();
  EXPECT_DOUBLE_EQ(bat.level(), MAX_LEVEL);
}

// Test 1. Verify battery can be depleted.
// Test 2. Verify robot battery will not go below 0.0
// Test 3. Verify different robot speeds causes different rates of depletion.
// Test 4. Verify no time elapsed causes no depletion
TEST(RobotBattery, DepleteBattery) {
  // Test 1
  csci3081::RobotBattery bat(MAX_LEVEL);
  bat.Deplete(Position(0, 0),
                        Position(1, 1), 1.0);
  EXPECT_LT(bat.level(), MAX_LEVEL) << "FAIL: Battery does not deplete";

  // Test 2
  bat.Reset();
  for (int i=0;i<1000;i++) {
    bat.Deplete(Position(1, 1), Position(100, 100), 1);
  }
  bat.Deplete(Position(1,1), Position(100,100), 1);
  EXPECT_DOUBLE_EQ(0, bat.level()) <<
      "FAIL: Battery level depleted below 0.0, or did not deplete sufficiently";

  // Test 3
  bat.Reset();
  bat.Deplete(Position(0, 0), Position(10, 10), 1.0);
  double lvl1 = bat.level();
  bat.Reset();
  bat.Deplete(Position(0, 0), Position(20, 20), 1.0);
  EXPECT_LT(bat.level(), lvl1) <<
      "FAIL: Different robot speeds should cause different depletions";

  // Test 4
  bat.Reset();
  bat.Deplete(Position(0, 0), Position(0, 0), 0);
  EXPECT_DOUBLE_EQ(bat.level(), MAX_LEVEL) <<
      "FAIL: Battery depletion without movement";
}

#endif /* PRIORITY1_TESTS */
