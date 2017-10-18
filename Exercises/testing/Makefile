# CSCI3081 In-Class Exercise dynamic allocation and arrays

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
TESTOBJS =
OBJS = main.o robot.o tests.o

all: $(OBJS)
	$(CC) $(LFLAGS) -o unittests $(OBJS)

%.o : %.cc
	$(CC) $(CFLAGS) -o $@ $<

clean:
	\rm *.o *.*~ unittests
