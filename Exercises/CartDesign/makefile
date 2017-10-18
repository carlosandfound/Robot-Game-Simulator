# CSCI3081 cart exercise makefile

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: main.o cart.o
	$(CC) $(LFLAGS) main.o cart.o -o cart

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp -o main.o

robot.o : cart.cpp
	$(CC) $(CFLAGS) cart.cpp -o cart.o

clean:
	\rm *.o *.*~ cart
