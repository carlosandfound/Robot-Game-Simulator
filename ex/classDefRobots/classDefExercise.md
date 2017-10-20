### Demonstration of Class Definition in C++

<hr>
This first example makes use of the default constructor, but this is problematic due to initialization.

#### Robot.h

```C++
class Robot {
private:
  float directionAngle;
  int position[2];

public:
  void moveForward( int distance );
  void display();
};
```

#### Robot.cpp

```C++
#include "robot.h"
#include <math.h>
#include <iostream>

void Robot::moveForward(int distance) {
  position[0] = position[0] + distance*cos(directionAngle);
  position[1] = position[1] + distance*sin(directionAngle);
}

void Robot::display() {
  cout << "Pos [" << position[0] << " " << position[1] << "]. angle "
  << directionAngle << endl;
}
```

#### main.cpp

In C++, _main()_ serves as the entry point to the program. It must exist to generate an executable.

```C++
#include "robot.h"
#include <iostream>

using std::cout;

int main() {
  Robot rosyRobot;
  rosyRobot.display();
}
```

You can compile the program using the provided makefile, then call the executable _robot_.

```
make
./robot
```

<hr>
We will fix the initialization problem by adding "setters" and add some "getters" while we are at it.

#### Robot.h

```C++
class Robot {
private:
  float directionAngle;
  int position[2];

public:
  // setters and getters
  void position( int x, int y);
  int* position();
  void radianDirectionAngle(float theta);
  float radianDirectionAngle();

  void moveForward( int distance );
  void display();
};
```

#### Robot.cpp

Adding the following to the source code.

```C++
// setters and getters
void Robot::xyPosition( int x, int y) {
  position[0] = x;
  position[1] = y;
}
int* Robot::xyPosition() {
  return position;
}

void Robot::radianDirectionAngle(float theta) {
  directionAngle = theta;
}
float Robot::radianDirectionAngle() {
  return directionAngle;
}
```

#### main.cpp

```C++
int main() {
  Robot rosyRobot;
  rosyRobot.xyPosition(0,0);
  rosyRobot.radianDirectionAngle(0);

  rosyRobot.display();
}
```

<hr>
This is dangerous to require users to initialize. Let's fix this by forcing the user to provide initialization.

#### Adding to Robot.h

We can pass along an array, but let's not do that right now. We will see why later.

```C++
  Robot( int x, int y, float theta );
```


#### Adding to Robot.cpp

```C++
Robot( int x, int y, float theta ) {
  position[0] = x;
  position[1] = y;
  directionAngle = theta;
}
```

<hr>
This can be cumbersome, let's give the user some options.

OPTION 1: Add a no-parameter constructor that initializes to reasonable values.

<hr>

#### Adding to robot.h

```C++
public:
  Robot();
```

#### Adding to robot.cpp

```C++
Robot::Robot() {
  position[0] = 0;
  position[1] = 0;
  directionAngle = 0;
}
```

#### Change main.cpp

```C++
int main() {
  Robot rosyRobot;
  rosyRobot.display();
}
```

OPTION 2: Add a constructor with a subset of the member variables.

#### Adding to robot.h

```C++
public:
  Robot();
  Robot( int x, int y );
  Robot(float theta);
```

Then you will add these definitions to robot.cpp. Let's see how we use them.

#### main.cpp

```C++
int main() {
  Robot rosyRobot;
  Robot c3poRobot(100,100);
  Robot halRobot(0,0,3.14/2);
  Robot eveRobot(-100,-100,-3.14/4);
  rosyRobot.display();
  c3poRobot.display();
  halRobot.display();
  eveRobot.display();
}
```

Looks like this when you run it ...

```
Pos [0 0]. angle 0
Pos [100 100]. angle 0
Pos [0 0]. angle 1.57
Pos [-100 -100]. angle -0.785
```

OPTION 3: (Probably the best) Create a single constructor that can take 1 to all member variable initializations.

Now we have to undo some of our work. We need only the one constructor, because we will add _default_ values.

#### robot.h

```C++
  Robot( int x=0, int y=0, float theta=0);
```

#### robot.cpp

```C++
Robot::Robot( int x, int y, float theta ) {
  position[0] = x;
  position[1] = y;
  directionAngle = theta;
}
```

#### main.cpp

There was no need to change anything in main from before. All of the various forms of constructors was captured in the one constructor with default arguments.

```C++
int main() {
  Robot rosyRobot;
  Robot c3poRobot(100,100);
  Robot halRobot(3.14);
  Robot eveRobot(-100,-100,-3.14/4);
  rosyRobot.display();
  c3poRobot.display();
  halRobot.display();
  eveRobot.display();
}
```

And it comes out like this ...
```
Pos [0 0]. angle 0
Pos [100 100]. angle 0
Pos [3 0]. angle 0
Pos [-100 -100]. angle -0.785
```

*__OOPS__*. What happened to hal? We specified an angle of 3.14, but that didn't work. Can you explain that?

<hr>
#### Position is awkward and prone to error. Let's fix that with a class definition.

```
struct Position {
  int x;
  int y;
};
```

But now we have to change all of our code. Too bad we didn't think about this change before we started!
