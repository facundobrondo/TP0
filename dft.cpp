#include "dft.h"

void dft(Array<Complex> &in, Array<Complex> &out){

	Complex result;

	for(size_t k = 0; k < in.getSize(); k++){

		result = 0;

		for(size_t n = 0; n < in.getSize(); n++)
			result += in[n] * Wn(n, k, in.getSize());

		out += result;

	}

}

void idft(Array<Complex> &in, Array<Complex> &out){

	Complex result;

	for(size_t n = 0; n < in.getSize(); n++){

		result = 0;

		for(size_t k = 0; k < in.getSize(); k++)
			result += in[k] * Wn(n, k, in.getSize(), false);

		result /= in.getSize();
		out += result;

	}

}

Complex Wn(size_t n, size_t k, size_t N, bool positive){

	if(positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));

}

void fourierProcess(istream &is, ostream &os, bool performDft){

	string line;

	while(getline(is, line)){

		stringstream stream(line);

		Array<Complex> input, output;

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
