#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include <iostream>
#include <fstream>

#include "Status.h"

using namespace std;

ostream &setOutStream(Status &, fstream &);
istream &setInStream(Status &, fstream &);

#endif