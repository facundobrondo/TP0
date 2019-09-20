#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED

#include <iostream>
#include <fstream>

#include "Array.h"
#include "Complex.h"
#include "dft.h"

class Signal{

	Array<Complex> inputSignal;
	Array<Complex> outputSignal;

	bool dftEnabled;

public:

	//Builders

	Signal();
	~Signal();

	//Status

	bool performDft();

	//Modifiers

	void dft();


}

Signal::Signal(){
	bool dftEnabled = true;
}

Signal::~Signal(){}

bool Signal::performDft(){
	return dftEnabled;
}

void Signal::dft(){

	Complex result;

	for(size_t k = 0; k < inputSignal.getSize(); k++){

		result = 0;

		for(size_t n = 0; n < inputSignal.getSize(); n++)
			result += inputSignal[n] * Wn(n, k, inputSignal.getSize());

		outputSignal += result;

	}

}

void Signal::idft(){

	Complex result;

	for(size_t n = 0; n < inputSignal.getSize(); n++){

		result = 0;

		for(size_t k = 0; k < inputSignal.getSize(); k++)
			result += inputSignal[k] * Wn(n, k, inputSignal.getSize(), false);

		result /= inputSignal.getSize();
		outputSignal += result;

	}

}

Complex Wn(size_t n, size_t k, size_t N, bool positive){

	if(positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));

}

void fourierProcess2(istream &is, ostream &os, bool performDft){

	string line;

	while(getline(is, line)){

		stringstream stream(line);

		//Array<Complex> input, output;
		Signal input;

		stream >> input;

		if(input.isEmpty())
			break;

		os << "Input Array: " << fixed << setprecision(2) << input << endl;

		if(performDft){
			os << "performing DFT" << endl;
			dft(input, output);
		}

		else{
			os << "performing iDFT" << endl;
			idft(input, output);
		}

		os << "Output Array: " << fixed << setprecision(2) << output << endl;

	}

}








#endif


