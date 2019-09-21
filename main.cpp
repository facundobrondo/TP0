#include "main.h"

using namespace std;

int main(int argc, char *argv[]){

	//Status object is created to keep count of the program attributes

	Status program;
	fstream input, output;
	Signal inSignal;

	if(!argumentProcessing(argc, argv, program)){

		if(program.needHelp())
			displayHelp();

		else
			displayError();

		return 1;

	}

	ostream &os = setOutStream(program, output);
	istream &is = setInStream(program, input);

	if(program.dft())
		inSignal.setMethod(DFT);

	else
		inSignal.setMethod(IDFT);	

	inSignal.fourierProcess(is, os);

	if(input.is_open())
		input.close();

	if(output.is_open())
		output.close();	

	return 0;

}


