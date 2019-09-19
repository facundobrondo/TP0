#include <iostream>
#include <fstream>

#include "Array.h"
#include "Complex.h"
#include "Status.h"
#include "CommandLineArguments.h"

using namespace std;

int main(int argc, char *argv[]){

	//Status object is created to keep count of the program attributes
	
	Status program;	

	fstream input, output;

	if(!argumentProcessing(argc, argv, program)){

		if(program.needHelp())
			displayHelp();

		return 1;

	}

	//Command line arguments have been read and the program status has been set

	//ostream object is created with no buffer
	ostream os(nullptr);

	//If stdout is selected, then the ostream object uses cout's buffer object
	if(program.stdOut()){
		puts("entro a stdout");
		os.rdbuf(cout.rdbuf());

	}

	//If a file is preffered, then a file buffer object is selected
	else{
		output.open(program.getOutFile(), ios::out);
		os.rdbuf(output.rdbuf());
	}

	//Program finishes

	if(output.is_open())
		output.close();

	return 0;


}