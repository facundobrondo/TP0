CC = g++
CFLAGS = -g -Wall -pedantic
SRCS = test.cpp Complex.cpp CommandLineArguments.cpp
OBJS= main.o Complex.o CommandLineArguments.o Status.o
OBJS_TEST = test.o Complex.o CommandLineArguments.o Status.o
EXEC = tp0

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

all: main

main: main.o Complex.o CommandLineArguments.o Status.o
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp Array.h CommandLineArguments.h Complex.h Status.h
	$(CC) -c main.cpp

Complex.o: Complex.cpp Complex.h 
	$(CC) -c Complex.cpp

CommandLineArguments.o: CommandLineArguments.cpp CommandLineArguments.h
	$(CC) -c CommandLineArguments.cpp

Status.o: Status.cpp Status.h
	$(CC) -c Status.cpp

test: test.o Complex.o CommandLineArguments.o Status.o 
	$(CC) $(CFLAGS) -o test $(OBJS_TEST) 

test.o: test.cpp Array.h Complex.h Status.h CommandLineArguments.h
	$(CC) -c test.cpp


clean: 
	rm *.o
