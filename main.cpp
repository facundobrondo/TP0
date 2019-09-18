#include <iostream>

#include "Array.h"
#include "Complex.h"
#include "Status.h"
#include "CommandLineArguments.h"

using namespace std;

int main(int argc, char *argv[]){
	
	Status program;	

	if(!argumentProcessing(argc, argv, program)){
		puts("Error");
		return 1;
	}

	cout << (program.dft() ? "DFT" : "iDFT") << endl;
	cout << "I:" << program.getInFile() << endl;
	cout << "O:" << program.getOutFile() << endl;
	cout << (program.stdIn() ? "stdin" : "inFile") << endl;
	cout << (program.stdOut() ? "stdout" : "outFile") << endl;

	return 0;


}