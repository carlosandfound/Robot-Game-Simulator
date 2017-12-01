#ifndef PROJECT_ITERATION2_SRC_MAINPAGE_H_
#define PROJECT_ITERATION2_SRC_MAINPAGE_H_

/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 *
 * \section intro_sec Introduction
 *
 * Software Overview
 *
 * The purpose of the software is to simulate robots moving across an arena full of different obstacles. The robot that’s
 * being controlled by the user is actually called a player and has a class called Player. Other entities include
 * autonomous robots, a homebase, a recharge station, and multiple obstacles. When the player collides with a robot,
 * the robot is frozen. The robot can only be unfrozen by another robot or superbot. If the player freezes all the robots,
 * the game is won. If all the populating robots become superbots by colliding with homebase, the game is lost.
 * Moreover, a superbot can freeze the player for a fixed amount of time.
 *
 * The first major component of the project that accomplishes this simulation is the GraphicsArenaViewer class because it
 * creates and displays the arena that contains the player, robot and obstacles so that they’re visible to the user.
 * Moreover two simulation controls buttons “pause” and “restart” are displayed in the arena.  At each simulation update,
 * it’s checked whether or not the game has been won or lost. When either case happens, the win/lose tally is updated in
 * the Simulation Controls menu and the game is restarted. Moreover, the graphics are separated from the arena by an
 * invisible wall that limits the robot and obstacles to a specified window where they won’t interact with the simulation
 * controls. Graphics is also separated from robot by implementing a color struct whose sole purpose to contain information
 * about the colors used in the simulation.
 *
 * The second major component of the simulation is the Arena class that manipulates the arena entities. The two types of
 * entities are mobile ones (i.e player, robot/superbot and home base) and immobile ones
 * (i.e. recharge station and obstacles). This manipulation is accomplished is by sending messages of various arena events
 * to the robot in order for it to deal with it within it’s own environment. The types of events are the following:
 * - EventKeyPress : key press from user is registered
 * - EventCommand : key press from user is translated into an appropriate command that changes the robot’s direction or speed
 * - EventRecharge : message is displayed when the battery of the robot is completely recharged when it reaches the
 *                   recharge station
 * - EventCollision : collision with an arena obstacle or wall is registered to make the robot bounce off at angle of
 *                    reflection.
 * - EventProximity : determine if an entity is within range of the proximity sensor of the autonomous robot.
 * - EventDistressCall : distress call signal is registered from a frozen robot
 * - EventTypeEmit : type of the entity within range of the sensor is registered
 * All these commands are part of a larger EventBaseClass from which they inherit and the robot, player, and home base
 * classes accept different events that they’re equipped to deal with.
 *
 * The final major component of the project is the Robot and Player classes because the former has to behave autonomously
 * while the latter is being controlled by the user. Composition on the player is achieved by it accepting different arena
 * events and sending those events to other smaller component classes that it creates and cumulatively form the player.
 * The first of these smaller classes is RobotBattery, which focuses on controlling the battery level of the player and robot.
 * Another class is SensorTouch, which inherits from SensorBaseClass, and acts a sensor that registers collisions and angles
 * of contact on the player, as well as robot. While the player only has a sensor proximity, robots have the following
 * additional sensors:
 * - SensorProximity : detects entities within a certain range
 * - SensorDistress : registers distress signal from a frozen robot
 * - SensorEntityType : registers the entity type of the entity if it is within range
 * Both Robot and Player contain a RobotMotionBehavior that maintains information about the their positions in the arena.
 * However, Robot has MotionHandlerRobot while Player contains MotionHandlerPlayer. These distinct motion handlers allow
 * robots to use the sensor information to change its heading angles and avoid collision with any entity besides homebase
 * (since robots needs it to become a superbot) that’s within a defined range of its proximity sensors. Meanwhile, the
 * player’s motion handler is only concerned with changing the heading angle in wake of a collision. Therefore, the speed
 * and direction of the player and robot are manipulated differently. However, all entities always bounce off each other
 * at angle of reflection. Moreover, the motion handler of a robot may not always behave the same. Specifically, if the
 * robot collides with home base and becomes a superbot, the motion handler would appropriately manipulate the heading
 * angle of the robot so that it never avoids objects and keeps its speed fixed. Thus, it’ll be able to unfreeze robots
 * and freeze the player.
 */
#endif  // PROJECT_ITERATION2_SRC_MAINPAGE_H_
