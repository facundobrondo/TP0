#include <iostream>
#include <fstream>

#include "Array.h"
#include "Complex.h"
#include "Status.h"
#include "CommandLineArguments.h"
#include "dft.h"
#include "stream.h"

using namespace std;

void fourierProcess(istream &, ostream &, bool);

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

	fourierProcess(is, os, program.dft());

	if(input.is_open())
		input.close();

	if(output.is_open())
		output.close();	

	return 0;

}

void fourierProcess(istream &is, ostream &os, bool performDft){

	string line;

	while(getline(is, line)){

		stringstream stream(line);

		Array<Complex> input, output;

		stream >> input;

		if(input.isEmpty())
			break;

		os << "Input Array: " << fixed << setprecision(2) << input << endl;

		if(performDft ? os << "performing DFT" << endl : os << "performing iDFT" << endl)
			dft(input, output);

		else
			idft(input, output);

		os << "Output Array: " << fixed << setprecision(2) << output << endl;

	}

}



