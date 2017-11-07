#ifndef PROJECT_ITERATION1_SRC_MAINPAGE_H_
#define PROJECT_ITERATION1_SRC_MAINPAGE_H_

/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * @copyright 2017 Carlos Alvarenga, All rights reserved.
 *
 * \section intro_sec Introduction
 *
 * Initial UML Write-up
 *
 * The purpose of the software is to simulate robots (Robot class) in an Arena (Arena class). The three main parts of the
 * software are the Arena, Robot and GraphicsArenaViewer classes that all interact with interact with event classes that
 * inherit from the EventBaseClass. The robots will be displayed through the GraphicsArenaViewer class that controls the
 * Arena class, tracks key and mouse events (EventKeyPress), and perform the actual drawings like HomeBase on the
 * graphics window. The Arena * *class contains important properties like the robot recharge station (RechargeStation),
 * obstacles (Obstacle), and arena entities (ArenaEntity / ArenaMobileEntity / ArenaImmobileEntity) that provide vital
 * information like speed and position of the entities (i.e. robots) in the arena. The Robot class contains different
 * properties like the battery (RobotBattery), sensor (SensorTouch), and motion handling/behavior (RobotMotionHandler
 * and RobotMotionBehavior) of the robots themselves that maintain vital information like the speed, heading angle, and
 * points of contact with other arena objects. Lastly, both Robot and Arena associate themselves with events that all
 * inherit from EventBaseClass. Specifically, Arena uses EventCollision to track collisions while Robot consults
 * EventRecharge to output a message whenever the robot battery has been recharged.
 *
 *
 * Final Submission Write-up & Overview
 *
 * The purpose of the software is to simulate a robot moving  across an arena full of different obstacles. If the robot
 * reaches the home base entity, the game is won. If the robot loses all it’s battery power, the game is lost.
 *
 * The first major component of the project that accomplishes this simulation is the GraphicsArenaViewer class because
 * it creates and displays the arena that contains the robot and obstacles so that they’re visible to the user. Moreover
 * two simulation controls buttons “pause” and “restart” are displayed in the arena.  At each simulation update, it’s
 * checked whether or not the game has been won or lost. When either case happens, the appropriate message is displayed
 * in place of the pause button. The user can then decide whether or not to restart the game. Moreover, the graphics are
 * separated from the arena by an invisible wall that limits the robot and obstacles to a specified window where they
 * won’t interact with the simulation controls. Graphics is also separated from robot by implementing a color struct
 * whose sole purpose to contain information about the colors used in the simulation. This is used in place of
 * relying nanogui color types that fail to differentiate between the graphics aspect of the project and robot.
 *
 * The second major component of the simulation is the Arena class that manipulates the arena entities. The two types
 * of entities are mobile ones (i.e robot and home base) and immobile ones (i.e. recharge station and obstacles). This
 * manipulation is accomplished is by sending messages of various arena events to the robot in order for it to deal
 * with it within it’s own environment. The four types of events are the following: EventKeyPress where a click on a
 * keyboard key is registered, EventCommand where such click is translated into an appropriate command that changes the
 * robot’s direction or speed, EventRecharge where a message is displayed when the battery  of the robot is completely
 * recharged when it reaches the recharge station, and EventCollision  where a collision with an arena obstacle or wall
 * is registered to make the robot bounce off at angle of reflection. All these commands are part of a larger Event base
 * class from which they inherit and these commands are sent to the robot class by the arena since the robot has the
 * necessary properties to deal with the events in the appropriate manner.
 *
 * The final major component of the project is the robot class because it’s the one being controlled by the user.
 * Composition on the robot is achieved by the robot accepting different arena events and sending those events to other 
 * smaller component classes that it creates and cumulatively form the robot. The first of these smaller classes is
 * RobotBattery, which focuses on controlling the battery level of the robot. Another class is SensorTouch, which
 * inherits from a SensorBaseClass, which acts a sensor that registers collisions and angles of contact on the robot.
 * RobotMotionBehavior is another component class that maintains information about the robot’s position in the arena
 * and RobotMotionHandler is the final component class that controls the speed and heading direction of the robot. These
 * four component classes form the robot and accept messages from robot to control unique aspects of the robot, such as
 * speed, direction, position, or battery level.
 *
 * One final notable aspect of the project that was changed is that home base was made mobile. This was accomplished by
 * making it inherit from Robot instead of ArenaImmobileEntity. Thus, home base acts similarly to robot in that it moves
 * and bounces off of obstacles and walls. However, unlike robot, it can randomly change direction and it doesn’t have
 * components like battery or speed manipulated. Thus, both home base and robot are the only mobile entities that must
 * meet in order for the game to be won.

 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */
#endif  // PROJECT_ITERATION1_SRC_MAINPAGE_H_
