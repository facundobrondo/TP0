#ifndef STREAM_H_INCLUDED
#define STREAM_H_INCLUDED

#include <iostream>
#include <fstream>

#include "Status.h"

using namespace std;

//Set program input stream.
istream & setInStream(Status &, fstream &);
//Set program output stream.
ostream & setOutStream(Status &, fstream &);

#endif
