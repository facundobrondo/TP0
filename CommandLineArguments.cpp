#include "CommandLineArguments.h"

bool argumentProcessing(size_t argc, char *argv[], Array<string> &files){

	if(argc < 2)
		return false;

	Array<string> arguments(argc);
	char2stringArray(argc, argv, arguments);

	for(size_t i = 1; i < argc; i++){

		if(arguments[i] == "-h" || arguments[i] == "--help"){
			cout << "Display help." << endl;
			return false;
		}

		else if(arguments[i] == "-f" || arguments[i] == "--files"){
			
			for(size_t j = i + 1; j < argc ; j++){
				files +=  arguments[j];
			}

			return true;

		}

	}
	
	return false;

}

void char2stringArray(size_t size, char *cArray[], Array<string> &sArray){

	for(size_t i = 0; i < size; i++){

		size_t length = getLength(cArray[i]);
		convert2string(length, cArray[i], sArray[i]);

	}

}

size_t getLength(char *string){

	size_t i;

	for(i = 0; string[i] != '\0'; i++);

	return i;

}

void convert2string(size_t length, char cArray[], string &str){

	str = "";

	for(size_t i = 0; i < length; i++)
		str = str + cArray[i];

}

