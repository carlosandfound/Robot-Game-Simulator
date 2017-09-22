CXX = g++
CXXFLAGS = -Wall -c
LDFLAGS = -c
OBJS = Duck.o DecoyDuck.o main.o MallardDuck.o MuteQuack.o QuackBehavior.o Quack.o RubberDuck.o Squeak.o

all: $(OBJS)
	$(CXX) *.o -o ducks


Duck.o: Duck.h Duck.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) Duck.cpp

main.o: main.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) main.cpp

MallardDuck.o: MallardDuck.h MallardDuck.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) MallardDuck.cpp

MuteQuack.o: MuteQuack.h MuteQuack.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) MuteQuack.cpp

DecoyDuck.o: DecoyDuck.h DecoyDuck.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) DecoyDuck.cpp

QuackBehavior.o: QuackBehavior.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) QuackBehavior.cpp

Quack.o: Quack.h Quack.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) Quack.cpp

RubberDuck.o: RubberDuck.h RubberDuck.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) RubberDuck.cpp

Squeak.o: Squeak.h Squeak.cpp
	$(CXX) $(LDFLAGS) $(CXXFLAGS) Squeak.cpp

clean:
	rm -rf *.o
