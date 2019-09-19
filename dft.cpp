#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Array.h"
#include "Complex.h"
#include "Status.h"

#define PI 3.1415926536897932

using namespace std;

Array<Complex> & dft(Array<Complex> &);
Array<Complex> & idft(Array<Complex> &);
Complex Wn(size_t n, size_t k, size_t N, bool positive = true);

int main(void){

	Array<Complex> in;	

	ifstream inFile("dft.txt");

	inFile >> in;

	cout << "Vector de entrada: " << in << endl;

	Array<Complex> &out = dft(in);

	cout << setprecision(3) << "Vector de salida: " << out << endl;

	Array<Complex> &iout = idft(out);

	cout << setprecision(3) << "Vector de salida idft: " << iout << endl;

	inFile.close();

	return 0;

}

Array<Complex> & dft(Array<Complex> & in){

	Array<Complex> *ptr = new Array<Complex>;
	Array<Complex> &out = *ptr;

	Complex result;

	for(size_t k = 0; k < in.getSize(); k++){

		result = 0;

		for(size_t n = 0; n < in.getSize(); n++)
			result += in[n] * Wn(n, k, in.getSize());

		out += result;

	}

	return out;
}

Complex Wn(size_t n, size_t k, size_t N, bool positive){

	if(positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));

}

Array<Complex> & idft(Array<Complex> & in){

	Array<Complex> *ptr = new Array<Complex>;
	Array<Complex> &out = *ptr;

	Complex result;

	for(size_t n = 0; n < in.getSize(); n++){

		result = 0;

		for(size_t k = 0; k < in.getSize(); k++)
			result += in[k] * Wn(n, k, in.getSize(), false);

		result /= in.getSize();
		out += result;

	}

	return out;
}