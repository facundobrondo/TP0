CC = g++
CFLAGS = -g -Wall 
SRCS = test.cpp Complex.cpp CommandLineArguments.cpp
OBJS= main.o Complex.o CommandLineArguments.o
OBJS_TEST = test.o Complex.o
EXEC = tp0

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp Array.h CommandLineArguments.h Complex.h
	$(CC) -c main.cpp

Complex.o: Complex.cpp Complex.h 
	$(CC) -c Complex.cpp

CommandLineArguments.o: CommandLineArguments.cpp CommandLineArguments.h
	$(CC) -c CommandLineArguments.cpp



test: $(OBJS_TEST) 
	$(CC) $(CFLAGS) -o test $(OBJS_TEST) 

test.o: test.cpp Array.h Complex.h
	$(CC) -c test.cpp


clean: 
	rm *.o
