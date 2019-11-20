#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>

#include "Array.h"
#include "Complex.h"

#define PI 3.1415926536897932
#define METHODS 8

using namespace std;

Complex Wn(size_t, size_t, size_t, bool = true);
void addZeros(Array<Complex> &, size_t * = NULL);
size_t nextPowOf2(size_t , size_t * = NULL);
size_t inverseBit(size_t , size_t );
Array<Complex> bitReverseCopy(Array<Complex> &, size_t );

enum mode {IDFT, DFT, FFT, IFFT, ITFFT, ITIFFT};

class Signal {
	Array<Complex> inputSignal;
	Array<Complex> outputSignal;

	mode transform;

	Array<Complex> fastFourierTransform(Array<Complex>, bool = false);

public:

	//Builders
	Signal();
	Signal(const Signal &);
	~Signal();

	//Status
	mode getMethod() const;
	bool isInputEmpty() const;
	Array<Complex> &getInput();
	Array<Complex> &getOutput();

	//Modifiers
	void dft();
	void idft();
	void fft();
	void ifft();
	void iterfft();
	void setMethod(mode);
	void emptyInput();
	void reset();
	void fourierProcess(istream &is, ostream &os);
	void discreteFourierTransform(bool = false);
	
	//Operators
	friend ostream & operator<<(ostream &, Signal &);
	friend istream & operator>>(istream &, Signal &);
};

extern void (Signal::*foutier[METHODS])();

#endif
