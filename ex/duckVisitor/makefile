# CSCI3081 Ducks Exercise makefile

CXX = g++
DEBUG = -g
CXXFLAGS = -Wall -c $(DEBUG)
LDFLAGS = -Wall $(DEBUG)
OBJS = Duck.o Visitor.o Fly.o Quack.o

all: duckVisitor.o $(OBJS)
	$(CXX) $(LDFLAGS) -o duckVisitor duckVisitor.o $(OBJS)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<


clean:
	\rm *.o *.*~ duckVisitor
