#include "Signal.h"

using namespace std;

//Builders--------------------------------------
Signal::Signal() {
	transform = DFT;
}

Signal::Signal(const Signal &right) {
	inputSignal = right.inputSignal;
	outputSignal = right.outputSignal;
	transform = right.transform;
}

Signal::~Signal() {}

//Status-----------------------------------------
bool Signal::isInputEmpty() const {
	if(inputSignal.isEmpty())
		return true;

	return false;
}

mode Signal::getMethod() const {
	return transform;
}

Array<Complex> & Signal::getInput() {
	return inputSignal;
}

Array<Complex> & Signal::getOutput() {
	return outputSignal;
}


//STD operators---------------------------------

ostream & operator<< (ostream &os, Signal &sig){
	os << fixed << setprecision(6) << sig.getOutput() << endl;
	return os;
}

istream & operator>> (istream &is, Signal &sig) {
	sig.reset();

	is >> sig.inputSignal;

	return is;
}

//Modifiers--------------------------------------
void Signal::dft(){

	Complex result;

	for(size_t k = 0; k < inputSignal.getSize(); k++) {
		result = 0;

		for (size_t n = 0; n < inputSignal.getSize(); n++)
			result += inputSignal[n] * Wn(n, k, inputSignal.getSize());

		outputSignal += result;
	}
}

void Signal::idft() {
	Complex result;

	for(size_t n = 0; n < inputSignal.getSize(); n++) {
		result = 0;

		for (size_t k = 0; k < inputSignal.getSize(); k++)
			result += inputSignal[k] * Wn(n, k, inputSignal.getSize(), false);

		result /= inputSignal.getSize();
		outputSignal += result;
	}
}

void Signal::setMethod(mode m) {
	transform = m;
}

void Signal::emptyInput() {
	inputSignal.empty();
}

void Signal::reset(){
	inputSignal.empty();
	outputSignal.empty();
}

void Signal::fourierProcess(istream &is, ostream &os) {
	string line;

	while (getline(is, line)) {
		stringstream stream(line);

		stream >> (*this);

		if (stream.bad()) {
			os << "Bad input" << endl;
			continue;
		}

		//if ((*this).isInputEmpty())
		if ( inputSignal.isEmpty() )
			continue;

		//if ((*this).getMethod() == DFT)
		if (transform == DFT)
			dft();
		else if (transform == IDFT)
			idft();
		else {
			os << "No operation selected" << endl;
			break;
		}

		os << (*this);
	}
}

//Auxiliary function----------------------------------------
Complex Wn(size_t n, size_t k, size_t N, bool positive) {
	if(positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));
}
