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