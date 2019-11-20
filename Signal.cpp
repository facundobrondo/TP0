#include "Signal.h"

using namespace std;

void (Signal::*fourier[METHODS])() = {&Signal::idft, &Signal::dft, &Signal::fft, &Signal::ifft, &Signal::iterfft, &Signal::iterifft};

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

void Signal::dft(){
	discreteFourierTransform();
}

void Signal::idft(){
	discreteFourierTransform(true);
}

void Signal::iterfft(){
	size_t bits = 0;

	addZeros(inputSignal, &bits);
	outputSignal = iterFourierTransform(inputSignal, bits);
}

void Signal::iterifft(){
	size_t bits = 0;

	addZeros(inputSignal, &bits);
	outputSignal = iterFourierTransform(inputSignal, bits, true);
}

void Signal::fft(){
	addZeros(inputSignal);
	outputSignal = fastFourierTransform(inputSignal);
}

void Signal::ifft(){
	addZeros(inputSignal);
	outputSignal = fastFourierTransform(inputSignal, true);
	outputSignal = outputSignal * (1.0 / inputSignal.getSize());
}

Array<Complex> Signal::fastFourierTransform(Array<Complex> x, bool inverse){
	
	size_t N = x.getSize();

	if(N > 1){

		Array<Complex> X(N);

		Array<Complex> p = x.evenIndex();
		Array<Complex> q = x.oddIndex();

		Array<Complex> P = fastFourierTransform(p, inverse);
		Array<Complex> Q = fastFourierTransform(q, inverse);

		for(size_t k = 0; k < N / 2; k++)
			X[k] = P[k] + Q[k] * Wn(1, k, N, !inverse);

		for(size_t k = N / 2; k < N; k++)
			X[k] = P[k - N / 2] + Q[k - N / 2] * Wn(1, k, N, !inverse);

		return X;

	}

	else 
		return x;

}

Array<Complex> Signal::iterFourierTransform(Array<Complex> x, size_t bits, bool inverse){

	Array<Complex> invertedX = bitReverseCopy(x, bits);

	cout << invertedX << endl;

	size_t n = invertedX.getSize();

	for(size_t s = 1; s <= log2(n); s++){

		size_t m = pow(2, s);
		Complex wm = Wn(1, 1, m, !inverse);

		for(size_t k = 0; k < n; k += m){

			Complex w = 1;

			for(size_t j = 0; j < m / 2; j++){

				Complex t = invertedX[k + j];
				Complex u = w * invertedX[k + j + m / 2];

				invertedX[k + j] = t + u;
				invertedX[k + j + m / 2] = t - u;
				w *= wm;
			}
		}

	}

	return inverse ? invertedX * (1.0 / n) : invertedX;

}

void Signal::discreteFourierTransform(bool inverse){

	Complex result;

	for(size_t n = 0; n < inputSignal.getSize(); n++){
		result = 0;

		for (size_t k = 0; k < inputSignal.getSize(); k++)
			result += inputSignal[k] * Wn(n, k, inputSignal.getSize(), !inverse);

		if(inverse)
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

void addZeros(Array<Complex> & in, size_t *bits){

	size_t newSize = (bits ? nextPowOf2(in.getSize(), bits) : nextPowOf2(in.getSize()));

	if(newSize != in.getSize()){

		Array<Complex> zeros(newSize - in.getSize());

		in += zeros;

	}

}

size_t nextPowOf2(size_t num, size_t *bits){

	size_t aux = num, i;

	for(i = 0; aux; i++)
		aux = aux >> 1;

	aux = pow(2, i - 1);

	if(num != aux){

		if(bits)
			*bits = i;

		return aux << 1;

	}

	if(bits)
		*bits = i - 1;

	return aux;

}

size_t inverseBit(size_t index, size_t bits){

	size_t inverted = 0, aux = 0;

	for(size_t i = 0; i < bits; i++){

		aux = (index & (1 << i));

		if(aux)
			inverted |= (1 << ((bits - 1) - i));

	}

	return inverted;

}

Array<Complex> bitReverseCopy(Array<Complex> &inputSignal, size_t bits){

	Array<Complex> reverse(inputSignal.getSize());

	for(size_t i = 0; i < inputSignal.getSize(); i++){

		reverse[inverseBit(i, bits)] = inputSignal[i];

	}

	return reverse;

}