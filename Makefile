#TP0 Makefile
CC = g++
CFLAGS = -g -Wall -pedantic
OBJS = Complex.o CommandLineArguments.o Status.o Signal.o stream.o
VALGRINDFLAGS = --tool=memcheck

#Run all
all: tp0 diff_tp0 test-dft test-idft test-fft test-ifft test-dft-valgrind test-idft-valgrind test-fft-valgrind test-ifft-valgrind

#install
install: tp0

#Create tp0 program
tp0: main.o $(OBJS)
	$(CC) $(CFLAGS) -o tp0 main.o $(OBJS)

main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c main.cpp

Signal.o: Signal.cpp Signal.h
	$(CC) $(CFLAGS) -c Signal.cpp

Complex.o: Complex.cpp Complex.h
	$(CC) $(CFLAGS) -c Complex.cpp

CommandLineArguments.o: CommandLineArguments.cpp CommandLineArguments.h
	$(CC) $(CFLAGS) -c CommandLineArguments.cpp

stream.o: stream.cpp stream.h
	$(CC) $(CFLAGS) -c stream.cpp

Status.o: Status.cpp Status.h
	$(CC) $(CFLAGS) -c Status.cpp

#Create diff_tp0 program
diff_tp0: diff_tp0.cpp $(OBJS)
	$(CC) $(CFLAGS) -o diff_tp0 diff_tp0.cpp cmdline.cpp $(OBJS)

#Run tests cases
#dft
test-dft: tp0 diff_tp0
	@echo Testing dft cases.
	@set -e; for t in `seq 1 9`; do                                  \
		echo Testing: $$t.;       			               			           \
		./tp0 < tests-dft/test$$t.in > tests-dft/test$$t.out;          \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out;  \
		./tp0 -m dft -i tests-dft/test$$t.in -o tests-dft/test$$t.out; \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out;  \
	done
	@echo Test OK.
#idft
test-idft: tp0 diff_tp0
	@echo Testing idft cases.
	@set -e; for t in `seq 10 17`; do                                   \
		echo Testing: $$t.;       			                 			            \
		./tp0 -m idft < tests-idft/test$$t.in > tests-idft/test$$t.out;   \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out;   \
		./tp0 -m idft -i tests-idft/test$$t.in -o tests-idft/test$$t.out; \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out;   \
	done
	@echo Test OK.
#fft
test-fft: tp0 diff_tp0
	@echo Testing fft cases.
	@set -e; for t in `seq 1 9`; do                                   \
		echo Testing: $$t.;       			                 			  					\
	  ./tp0 -m fft < tests-dft/test$$t.in > tests-dft/test$$t.out;   \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out;   \
		./tp0 -m fft -i tests-dft/test$$t.in -o tests-dft/test$$t.out; \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out;   \
	done
	@echo Test OK.
#ifft
test-ifft: tp0 diff_tp0
	@echo Testing ifft cases.
	@set -e; for t in `seq 10 17`; do                                   \
		echo Testing: $$t.;       			                 			  					\
  	./tp0 -m ifft < tests-idft/test$$t.in > tests-idft/test$$t.out;   \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out;   \
		./tp0 -m ifft -i tests-idft/test$$t.in -o tests-idft/test$$t.out; \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out;   \
	done
	@echo Test OK.

#Run tests cases with Valgrind
#dft
test-dft-valgrind: tp0 diff_tp0
	@echo Testing dft cases with Valgrind.
	@set -e; for t in `seq 1 9`; do                                      \
		echo Testing: $$t.;       			                     		           \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                              \
		./tp0 < tests-dft/test$$t.in > tests-dft/test$$t.out;         	   \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out ;     \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                              \
	  	./tp0 -m dft -i tests-dft/test$$t.in -o tests-dft/test$$t.out; 	 \
	  	./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out ;   \
	done
	@echo Test OK.
#idft
test-idft-valgrind: tp0 diff_tp0
	@echo Testing idft cases with Valgrind.
	@set -e; for t in `seq 10 17`; do                                       \
		echo Testing: $$t.;       			                         	            \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                                 \
		./tp0 -m idft < tests-idft/test$$t.in > tests-idft/test$$t.out;       \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out ;      \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                                 \
	  	./tp0 -m idft -i tests-idft/test$$t.in -o tests-idft/test$$t.out;   \
	  	./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out ;    \
	done
	@echo Test OK.
#fft
test-fft-valgrind: tp0 diff_tp0
	@echo Testing fft cases with Valgrind.
	@set -e; for t in `seq 1 9`; do                                      \
		echo Testing: $$t.;       			                     		           \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                              \
		./tp0 -m fft < tests-dft/test$$t.in > tests-dft/test$$t.out;         	   \
		./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out ;     \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                              \
	  	./tp0 -m fft -i tests-dft/test$$t.in -o tests-dft/test$$t.out; 	 \
	  	./diff_tp0 -r tests-dft/test$$t.ref -o tests-dft/test$$t.out ;   \
	done
	@echo Test OK.
#ifft
test-ifft-valgrind: tp0 diff_tp0
	@echo Testing ifft cases with Valgrind.
	@set -e; for t in `seq 10 17`; do                                       \
		echo Testing: $$t.;       			                         	            \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                                 \
		./tp0 -m ifft < tests-idft/test$$t.in > tests-idft/test$$t.out;       \
		./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out ;      \
		valgrind $(VALGRINDFLAGS) 2>/dev/null                                 \
	  	./tp0 -m ifft -i tests-idft/test$$t.in -o tests-idft/test$$t.out;   \
	  	./diff_tp0 -r tests-idft/test$$t.ref -o tests-idft/test$$t.out ;    \
	done
	@echo Test OK.

#Delete .o files
clean:
	rm *.o
