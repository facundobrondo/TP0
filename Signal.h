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

using namespace std;

Complex Wn(size_t, size_t, size_t, bool = true);
void addZeros(Array<Complex> &);

enum mode {IDFT, DFT};

class Signal {
	Array<Complex> inputSignal;
	Array<Complex> outputSignal;

	mode transform;

	Array<Complex> fastFourierTransform(Array<Complex>);

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
	void setMethod(mode);
	void emptyInput();
	void reset();
	void fourierProcess(istream &is, ostream &os);
	
	//Operators
	friend ostream & operator<<(ostream &, Signal &);
	friend istream & operator>>(istream &, Signal &);
};

#endif
