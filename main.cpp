#include <iostream>

#include "Array.h"
#include "Complex.h"
#include "CommandLineArguments.h"

using namespace std;

int main(int argc, char *argv[]){

	Array<string> files;	

	if(!argumentProcessing(argc, argv, files))
		return 1;

	cout << files;

}