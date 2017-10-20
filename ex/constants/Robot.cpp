#include <iostream>

class Robot {
	private:
		const int radius;
		const int color;
		int speed;
	public:
		Robot() : radius(50), color(0xFF0000) {speed = 250;}
		Robot(int r, int c, int s) {
			radius=r;
			color=c;
			speed=s;
		void setSpeed(int inS) {speed = inS;}
		void setColor (int inC) {color = inC;}
		int getSpeed() { return speed; }
		int getRadius() { return radius; }
		int getColor() { return color; }
};

int main() {
	Robot robot1(20, 0x00FF00, 200);
	const Robot robot2;

  std::cout << "Setting Robot1 speed to 45" << std::endl;
	robot1.setSpeed(45);
	int s = robot1.getSpeed();
  std::cout << "speed: " << s << std::endl;

	robot2.setSpeed(250);
	int s2 = robot2.getSpeed();
}
