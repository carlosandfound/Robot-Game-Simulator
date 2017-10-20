# CSCI3081 setterGetter makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OBJS = arena.o motion_behavior.o motion_handler.o robot_virtual.o robot.o

all: main.o $(OBJS)
	$(CC) $(LFLAGS) -o robots main.o $(OBJS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o *.*~ robots
