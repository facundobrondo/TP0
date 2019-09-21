#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <cmath>

#include "Array.h"
#include "Complex.h"
#include "Status.h"

#define PI 3.1415926536897932

using namespace std;

Complex Wn(size_t, size_t, size_t, bool = true);

enum mode {IDFT, DFT};

class Signal{

	Array<Complex> inputSignal;
	Array<Complex> outputSignal;

	mode transform;

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
	void setMethod(mode);
	void fourierProcess(istream &is, ostream &os);
	void emptyInput();
	void reset();

	//Operators

	friend ostream & operator<< (ostream &, Signal &);
	friend istream & operator>> (istream &, Signal &);

};


#endif