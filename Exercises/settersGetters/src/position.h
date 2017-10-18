/**
 * @file position.h
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

#ifndef SRC_POSITION_H_
#define SRC_POSITION_H_

struct Position {
  Position(void) : x(0),y(0) { }
  Position(int in_x, int in_y) : x(in_x), y(in_y) { }
  int x;
  int y;
};

#endif /* SRC_POSITION_H_ */
