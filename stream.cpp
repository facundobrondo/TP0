#include "stream.h"

istream & setInStream(Status &program, fstream &input){
	
	istream *isPtr = NULL;

	if (program.stdIn())
		isPtr = &cin;

	else{
		input.open(program.getInFile(), ios::in);
		isPtr = &input;
	}

	return *isPtr;
}

ostream & setOutStream(Status &program, fstream &output){

	ostream *osPtr = NULL;

	if(program.stdOut())
		osPtr = &cout;

	else{
		output.open(program.getOutFile(), ios::out);
		osPtr = &output;
	}

	return *osPtr;
}
