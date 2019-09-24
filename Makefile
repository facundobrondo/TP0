CC = g++
CFLAGS = -g -Wall -pedantic
SRCS = test.cpp Complex.cpp CommandLineArguments.cpp
OBJS= main.o Complex.o CommandLineArguments.o Status.o Signal.o stream.o
OBJS_TEST = test.o Complex.o CommandLineArguments.o Status.o Signal.o stream.o
EXEC = tp0
EXEC_T = test

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

all: main

main: main.o Complex.o CommandLineArguments.o Status.o Signal.o stream.o
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

main.o: main.cpp main.h
	$(CC) -c main.cpp

stream.o: stream.cpp stream.h
	$(CC) -c stream.cpp

Signal.o: Signal.cpp Signal.h
	$(CC) -c Signal.cpp

Complex.o: Complex.cpp Complex.h
	$(CC) -c Complex.cpp

CommandLineArguments.o: CommandLineArguments.cpp CommandLineArguments.h
	$(CC) -c CommandLineArguments.cpp

Status.o: Status.cpp Status.h
	$(CC) -c Status.cpp

test:
	./tp0 < tests/input_dft.txt > tests/output_dft.txt
	./tp0 -m idft < tests/input_idft.txt > tests/output_idft.txt
	diff tests/output_dft.txt tests/reference_dft.txt
	diff tests/output_idft.txt tests/reference_idft.txt
	rm tests/output_*

clean:
	rm *.o tests/output_*
