#ifndef DFT_H_INCLUDED
#define DFT_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include "Array.h"
#include "Complex.h"
#include "Status.h"

#define PI 3.1415926536897932

using namespace std;

void dft(Array<Complex> &, Array<Complex> &);
void idft(Array<Complex> &, Array<Complex> &);
Complex Wn(size_t n, size_t k, size_t N, bool positive = true);

#endif