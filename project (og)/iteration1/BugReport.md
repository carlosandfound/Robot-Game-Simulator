One notable bug present in the project is that the robot can sometime glitch and not
reflect accurately off of an obstacle. Moreover, the robot may also glitch when bouncing off
a wall after it's collided with an obstacle. These bugs don't appear every time but they
are present. One way that I've thought about fixing this is handling the calculation of the
reflection angle exclusively in RobotMotionHandler instead of Arena. Instead of having
if statements that update the angle of contact to a specific number based on the heading angle of
the robot and/or the tangent angle, a more involved formula using trigonometry to calculate the
angle of reflection could plugged in under UpdateVelocity() in RobotMotionHandler.cc whenever an
collision event is registered by the sensor. Moreover, then negative angles would be present in
the simulation instead of always having the heading angle be from 0 to 360.

One final thing that could have been improved is the limiting of the dimension in which robot
operates in so that GUI is not in arena. As of right now, an invisible left wall is placed at an
x-coordinate of 200 so that the arena entities don't interact with the GUI simulation controls.
In addition to implementing this, a line could have been drawn in GraphicsArenaViewer.cc
in order to fully visualize the left wall. Moreover, the top, bottom, and right wall
could also have lines drawn so that the full arena can be fully visualized by the user.
