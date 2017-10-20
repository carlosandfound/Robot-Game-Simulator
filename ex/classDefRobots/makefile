# CSCI3081 robot exercise makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o robot.o
	$(CC) $(LFLAGS) main.o robot.o -o robot

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

robot.o : robot.cpp
	$(CC) $(CFLAGS) robot.cpp -o robot.o

clean:
	\rm *.o *.*~ robot
