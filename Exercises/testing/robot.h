#ifndef TESTS_ROBOT_H_
#define TESTS_ROBOT_H_

struct Position {
  int x;
  int y;
  Position(): x(0), y(0) {}
  Position(int inX, int inY) : x(inX), y(inY) {}
};

class Robot {
public:
  Robot();
  Robot(int r, int x, int y);
  bool CheckOverlap(const Robot& robot2);
  Position get_position(void) const { return position; }
  int get_radius(void) const { return radius; }
private:
  int radius;
  Position position;
};

#endif
