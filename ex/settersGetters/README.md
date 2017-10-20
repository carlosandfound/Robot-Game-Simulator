## Design of Class Member Variables

The reason that there was a need for the fix to pos_ was due to an assumption
on my part about the design of the ArenaEntity. I did not look at it closely
enough and assumed setters and getters were implemented polymorphically.
Through testing it was discovered that the setters and getters were not
working when upcasting. It raises interesting questions about the design of
inheritance.

By defining member variables only in the parent class and making them private,
the user of the class is forced to use the setters and getters, rather than
having direct access to the member variables.

Questions:

1. Explain why overriding the variable position\_ and its getter in the non-virtual version does not work.
2. Explain why position\_ must be protected, rather than private in the virtual (polymorphic) version.
3. Draw a picture of each version of a robot, including all objects enclosed. Show where the member variable
position resides within the objects.
4. Imagine the non-virtual version, but with the replacement of position and get_pos in that class (i.e. like the version that
was in the class-repo). Draw that robot.
5. Identify the advantages and disadvantages of each version (not the incorrect one). Consider robustness and other programmers
using the code.
6. Heading and speed are stored inside of the motion_handler\_, yet these values are sometimes needed outside of the class
(e.g. when being drawn). Notice that there is a setter and getter for these variables in the robot class, yet they are not member variables of robot. What do you think about this design with respect to both robustness and use by other programmers. Do you think heading should also exist in robot and somehow be maintained between the motion_handler and the robot class? 

