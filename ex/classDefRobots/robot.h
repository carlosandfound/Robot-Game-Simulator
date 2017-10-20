class Robot {
 private:
  float directionAngle;
  int position[2];

 public:
  Robot(int x=0, int y=0, float theta=0);

  void moveForward( int distance );
  void display();

  // setters and getters
  void xyPosition( int x, int y);
  int* xyPosition();
  void radianDirectionAngle(float d);
  float radianDirectionAngle();

};
