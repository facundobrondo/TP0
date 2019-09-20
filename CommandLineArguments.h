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

#define MAX_LEN 9

extern const char flags[][MAX_LEN];

void char2stringArray(size_t size, char *cArray[], Array<string> &sArray);
size_t getLength(char *string);
void convert2string(size_t length, char cArray[], string &str);
bool argumentProcessing(size_t argc, char *argv[], Status &);
bool displayHelp();
bool displayError();
bool isFlag(string s);

#endif