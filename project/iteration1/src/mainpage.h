/*! \mainpage CSCI3081 Robot Simulator Project
 *
 * \section intro_sec Introduction
 *
 * The purpose of the software is to simulate robots (Robot class) in an Arena (Arena class). The three main parts of the software are the Arena, Robot and GraphicsArenaViewer classes that all interact with interact with event classes that inherit from the EventBaseClass. The robots will be displayed through the GraphicsArenaViewer class that controls the Arena class, tracks key and mouse events (EventKeyPress), and perform the actual drawings like HomeBase on the graphics window. The Arena class contains important properties like the robot recharge station (RechargeStation), obstacles (Obstacle), and arena entities (ArenaEntity / ArenaMobileEntity / ArenaImmobileEntity) that  provide vital information like speed and position of the entities (i.e. robots) in the arena. The Robot class contains different properties like the battery (RobotBattery), sensor (SensorTouch), and motion handling/behavior (RobotMotionHandler and RobotMotionBehavior) of the robots themselves that maintain vital information like the speed, heading angle, and points of contact with other arena objects. Lastly, both Robot and Arena associate themselves with events that all inherit from EventBaseClass. Specifically, Arena uses EventCollision to track collisions while Robot consults EventRecharge to output a message whenever the robot battery has been recharged.
 *

 * \section install_sec Installation
 *
 * \subsection libsimplegraphics Installing and Using libsimplegraphics
 *
 * etc...
 */
