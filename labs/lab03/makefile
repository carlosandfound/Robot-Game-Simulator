CXX = g++
CXXFLAGS = -Wall -c
LDFLAGS = -Wall
OBJS = Duck.o DecoyDuck.o main.o MallardDuck.o MuteQuack.o QuackBehavior.o Quack.o RubberDuck.o Squeak.o

all: $(OBJS)
	$(CXX) *.o -o ducks


Duck.o: Duck.h Duck.cpp
	g++ -c Duck.cpp

main.o: main.cpp
	g++ -c main.cpp
	$(CXX) $(CXXFLAGS) -o main.o main.cpp

MallardDuck.o: MallardDuck.h MallardDuck.cpp
	$(CXX) $(CXXFLAGS) MallardDuck.cpp

MuteQuack.o: MuteQuack.h MuteQuack.cpp
	$(CXX) $(CXXFLAGS) MuteQuack.cpp

DecoyDuck.o: DecoyDuck.h DecoyDuck.cpp
	$(CXX) $(CXXFLAGS) DecoyDuck.cpp

QuackBehavior.o: QuackBehavior.cpp
	$(CXX) $(CXXFLAGS) QuackBehavior.cpp

Quack.o: Quack.h Quack.cpp
	$(CXX) $(CXXFLAGS) Quack.cpp

RubberDuck.o: RubberDuck.h RubberDuck.cpp
	$(CXX) $(CXXFLAGS) RubberDuck.cpp

Squeak.o: Squeak.h Squeak.cpp
	$(CXX) $(CXXFLAGS) Squeak.cpp

clean:
	rm -rf *.o
