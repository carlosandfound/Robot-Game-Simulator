#include <iostream>

/* YOUR ASSIGNMENT. change
Pos incPos(Pos p) to Pos incPos( const &Pos p)
*/

class Pos{
	private:
		int x;
		int y;
	public:
		Pos(): x(0), y(0) {}
		Pos(int inX, int inY): x(inX), y(inY) {}
		void setX(int inX) { x=inX;}
		void setY(int inY) {y=inY;}
		int getX() {return x;}
		int getY() {return y;}
};

Pos incPos(Pos p) {
        std::cout << "=====In incPos=====" << std::endl;
	std::cout << "p x: " << p.getX() << ", p y: " << p.getY() << std::endl;
	int x = p.getX() + 2;
	int y = p.getY() + 3;
        p.setX(30);
	Pos pos(x, y);
	std::cout << "pos x: " << pos.getX() << ", pos y: " << pos.getY() << std::endl;
        std::cout << "=====Leaving incPos=====" << std::endl;
	return pos;
}

int calcDist(Pos p1, Pos p2) {
        std::cout << "=====In calcDist=====" << std::endl;
	std::cout << "p1 x: " << p1.getX() << ", p1 y: " << p1.getY() << std::endl;
	std::cout << "p2 x: " << p2.getX() << ", p2 y: " << p2.getY() << std::endl;

        std::cout << "=====Leaving calcDist=====" << std::endl;
	return 23;
}

int main() {
	Pos pos1(2,5);
	int dist;
        std::cout << "======Starting in main=========" << std::endl;
	std::cout << "pos1 x: " << pos1.getX() << ", pos1 y: " << pos1.getY() << std::endl;
	int x = pos1.getX() + 2;
        std::cout << "x value: " << x << std::endl;
	int x2 = incPos(pos1).getX();
        std::cout << "x2 value: " << x2 << std::endl;
	dist = calcDist(incPos(pos1), pos1);
        std::cout << "After calculations" << std::endl;
	std::cout << "x: " << x << ", x2: " << x2 << ", Dist: " << dist << std::endl;
	std::cout << "pos1 x: " << pos1.getX() << ", pos1 y: " << pos1.getY() << std::endl;
}
