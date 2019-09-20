#include <iostream>
#include <fstream>

#include "Array.h"
#include "Complex.h"
#include "Status.h"
#include "CommandLineArguments.h"

using namespace std;

ostream &setOutStream(Status &, fstream &);
istream &setInStream(Status &, fstream &);

int main(int argc, char *argv[]){

	//Status object is created to keep count of the program attributes

	Status program;

	fstream input, output;

	if(!argumentProcessing(argc, argv, program)){

		if(program.needHelp())
			displayHelp();

		return 1;

	}

	ostream &os = setOutStream(program, output);
	istream &is = setInStream(program, input);

	if(input.is_open())
		input.close();

	if(output.is_open())
		output.close();	

	return 0;


}

ostream &setOutStream(Status &program, fstream &output){

	ostream *osPtr = NULL;

	if(program.stdOut())
		osPtr = &cout;

	else{
		output.open(program.getOutFile(), ios::out);
		osPtr = &output;
	}

	return *osPtr;

}

istream &setInStream(Status &program, fstream &input){

	istream *isPtr = NULL;

	if(program.stdIn())
		isPtr = &cin;

	else{
		input.open(program.getInFile(), ios::in);
		isPtr = &input;
	}

	return *isPtr;

}
