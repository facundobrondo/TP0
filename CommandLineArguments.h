#ifndef CLA_H_INCLUDED
#define CLA_H_INCLUDED

#include <iostream>
#include <fstream>
#include "Array.h"
#include "Status.h"

#define HELP_FILE "help.txt"
#define ERROR_FILE "error.txt"

#define METHOD1 "-m"
#define METHOD2 "--method"
#define HELP1 "-h"
#define HELP2 "--help"
#define INPUT1 "-i"
#define INPUT2 "--input"
#define OUTPUT1 "-o"
#define OUTPUT2 "--output"

#define STANDARD "-"
#define DFT "dft"
#define IDFT "idft"
#define FFT "fft"
#define IFFT "ifft"
#define FFTITER "fft-iter"
#define IFFTITER "ifft-iter"

#define MAX_LEN 9
#define OPTIONS 3

extern const char flags[][MAX_LEN];

extern bool (*f[OPTIONS])(Status &, string &);

enum args{HELP, METHOD, INPUT, OUTPUT};

void char2stringArray(size_t size, char *cArray[], Array<string> &sArray);
size_t getLength(char *string);
void convert2string(size_t length, char cArray[], string &str);
bool argumentProcessing(size_t argc, char *argv[], Status &);
bool displayHelp();
bool displayError();
size_t isFlag(string s);
bool isHelp(string s);

bool processMethod(Status &, string &);
bool processInput(Status &, string &);
bool processOutput(Status &, string &);

#endif