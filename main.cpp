#include <iostream>

#include "Array.h"
#include "Complex.h"

using namespace std;

void char2stringArray(size_t size, char *cArray[], Array<string> &sArray);
size_t getLength(char *string);
void convert2string(size_t length, char cArray[], string &str);
bool argumentProcessing(size_t argc, char *argv[], Array<string> &files);

int main(int argc, char *argv[]){

	Array<string> files;	

	if(!argumentProcessing(argc, argv, files))
		return 1;

}

bool argumentProcessing(size_t argc, char *argv[], Array<string> &files){

	if(argc < 2)
		return false;

	Array<string> arguments(argc);
	char2stringArray(argc, argv, arguments);

	for(size_t i = 0; i < arguments.getSize(); i++){

		if(arguments[i] == "-h" || arguments[i] == "--help"){
			cout << "Display help." << endl;
			return false;
		}

		else if(arguments[i] == "-f" || arguments[i] == "--files"){

			for(size_t j = 0; i < files.getSize(); j++)
				files +=  arguments[j + i + 1];
			
			return true;

		}


	}

	return 0;

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

