#include "Signal.h"

using namespace std;

void (Signal::*fourier[METHODS])() = {&Signal::idft, &Signal::dft, &Signal::fft, &Signal::ifft, NULL, NULL};

//Builders--------------------------------------

Signal::Signal(){
	transform = DFT;
}

Signal::Signal(const Signal &right) {
	inputSignal = right.inputSignal;
	outputSignal = right.outputSignal;
	transform = right.transform;
}

Signal::~Signal(){}

//Status-----------------------------------------

bool Signal::isInputEmpty()const{
	if(inputSignal.isEmpty())
		return true;

	return false;
}

mode Signal::getMethod()const{
	return transform;
}

Array<Complex> & Signal::getInput(){
	return inputSignal;
}

Array<Complex> & Signal::getOutput(){
	return outputSignal;
}

//STDIO operators-------------------------------

ostream & operator<< (ostream &os, Signal &sig){
	os << fixed << setprecision(6) << sig.getOutput() << endl;
	return os;
}

istream & operator>> (istream &is, Signal &sig){
	sig.reset();

	is >> sig.inputSignal;

	return is;
}

//Modifiers--------------------------------------

void Signal::fft(){

	outputSignal = fastFourierTransform(inputSignal);

}

void Signal::ifft(){

	outputSignal = fastFourierTransform(inputSignal, true);

}

Array<Complex> Signal::fastFourierTransform(Array<Complex> x, bool inverse){

	size_t N = x.getSize();

	if(N > 1){

		Array<Complex> X(N);

		addZeros(x);

		Array<Complex> p = x.evenIndex();
		Array<Complex> q = x.oddIndex();

		Array<Complex> P = fastFourierTransform(p);
		Array<Complex> Q = fastFourierTransform(q);

		for(size_t k = 0; k < N / 2; k++)
			X[k] = P[k] + Q[k] * Wn(inverse ? -1 : 1, k, N);

		for(size_t k = N / 2; k < N; k++){
			X[k] = P[k - N / 2] + Q[k - N / 2] * Wn(inverse ? -1 : 1, k, N);
		}

		return inverse ? X * (1.0 / N) : X;

	}

	else
		return inverse ? x *(1.0 / N) : x;

}

void Signal::dft(){

	Complex result;

	for(size_t k = 0; k < inputSignal.getSize(); k++){
		result = 0;

		for (size_t n = 0; n < inputSignal.getSize(); n++)
			result += inputSignal[n] * Wn(n, k, inputSignal.getSize());

		outputSignal += result;
	}
}

void Signal::idft(){
	Complex result;

	for(size_t n = 0; n < inputSignal.getSize(); n++){
		result = 0;

		for (size_t k = 0; k < inputSignal.getSize(); k++)
			result += inputSignal[k] * Wn(n, k, inputSignal.getSize(), false);

		result /= inputSignal.getSize();
		outputSignal += result;
	}
}

void Signal::setMethod(mode m){
	transform = m;
}

void Signal::emptyInput(){
	inputSignal.empty();
}

void Signal::reset(){
	inputSignal.empty();
	outputSignal.empty();
}

void Signal::fourierProcess(istream &is, ostream &os){

	string line;

	while(getline(is, line)){

		stringstream stream(line);

		stream >> (*this);

		if (stream.bad()){
			os << "Bad input" << endl;
			continue;
		}

		if(inputSignal.isEmpty())
			continue;

		((*this).*fourier[transform])();

		os << (*this);

	}

}

//Auxiliary function----------------------------------------

Complex Wn(size_t n, size_t k, size_t N, bool positive){
	if(positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));
}

void addZeros(Array<Complex> & in){

	Complex zero;

	if(in.getSize() % 2)
		in += zero;

}
