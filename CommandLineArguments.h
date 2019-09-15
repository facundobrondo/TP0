#ifndef CLA_H_INCLUDED
#define CLA_H_INCLUDED

#include <iostream>
#include "Array.h"

#define HELP_FILE "help.txt"

void char2stringArray(size_t size, char *cArray[], Array<string> &sArray);
size_t getLength(char *string);
void convert2string(size_t length, char cArray[], string &str);
bool argumentProcessing(size_t argc, char *argv[], Array<string> &files);

#endif