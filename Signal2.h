#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include <cmath>
#include "Complex.h"

#define PI 3.1415926536897932

class Signal {
	public:
		Signal();
		Signal(const Signal &);
		~Signal();
		Signal & operator=(const Signal &);
		
		void loadTimeSignal(Array<Complex> &);
		void loadFrecSignal(Array<Complex> &);
		
		Complex & viewTimeSample(size_t);
		Complex & viewFrecSample(size_t);
		
		size_t lenght() const;
		
		bool isCorrupted() const;
		void setCorrupted();
		
		void dft();
		void idft();

	private:
		Array<Complex> t_signal;
		Array<Complex> f_signal;
		
		bool dft_calc;
		bool idft_calc;
		
		bool corrupted;
		
		Complex _Wn(size_t, size_t, size_t, bool positive = true);
};

Signal::Signal() {
	dft_calc = idft_calc = corrupted = false;
}

Signal::Signal(const Signal &s) {
	t_signal = s.t_signal;
	f_signal = s.f_signal;
	dft_calc = s.dft_calc;
	idft_calc = s.idft_calc;
	corrupted = s.corrupted;
}

Signal & Signal::operator=(const Signal &src) {
	t_signal = src.t_signal;
	f_signal = src.f_signal;
	dft_calc = src.dft_calc;
	idft_calc = src.idft_calc;
	corrupted = src.corrupted;
}

Signal::~Signal() {
}

void Signal::loadTimeSignal(Array<Complex> &src) {
	t_signal = src;
	
	dft_calc = false;
	idft_calc = true;
	
	return;
}

void Signal::loadFrecSignal(Array<Complex> &src) {
	f_signal = src;
	
	idft_calc = true;
	dft_calc = false;
	
	return;
}

Complex & Signal::viewTimeSample(size_t i) {
	return t_signal[i];
}


Complex & Signal::viewFrecSample(size_t i) {
	return f_signal[i];
}

bool Signal::isCorrupted() const {
	return corrupted;
}

void Signal::setCorrupted() {
	corrupted = true;
	
	return;
}

size_t Signal::lenght() const {
	if (idft_calc)
		return t_signal.size();
		
	return f_signal.size();
}

void Signal::dft() {
	f_signal.reserve(t_signal.size());

	Complex result_k;
	for (size_t k = 0; k < t_signal.size(); k++) {

		result_k = 0;

		for (size_t n = 0; n < t_signal.size(); n++)
			result_k += t_signal[n] * _Wn(n, k, t_signal.size());

		f_signal[k] = result_k;
	}

	dft_calc = true;

	return;
}

void Signal::idft() {
	t_signal.reserve(f_signal.size());

	Complex result_k;

	for (size_t k = 0; k < f_signal.size(); k++) {

		result_k = 0;

		for (size_t n = 0; n < f_signal.size(); n++)
			result_k += f_signal[n] * _Wn(n, k, f_signal.size(), false);

		t_signal[k] = result_k;
	}

	idft_calc = true;

	return;
}

Complex Signal::_Wn(size_t n, size_t k, size_t N, bool positive) {

	if (positive)
		return Complex(cos(2 * PI * n * k / N), - sin(2 * PI * n * k / N));

	return Complex(cos(2 * PI * n * k / N), sin(2 * PI * n * k / N));
}

#endif
