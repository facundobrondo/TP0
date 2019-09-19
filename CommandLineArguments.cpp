#include "CommandLineArguments.h"

bool argumentProcessing(size_t argc, char *argv[], Status &program){

	if(argc < 2)
		return false;

	Array<string> arguments(argc);
	char2stringArray(argc, argv, arguments);

	for(size_t i = 1; i < argc; i++){

		if(arguments[i] == "-h" || arguments[i] == "--help"){
			program.setHelp();
			return false;
		}

		else if(arguments[i] == "-m" || arguments[i] == "--method"){

			if(i + 1 < argc){

				if(arguments[i + 1] == "idft"){
					program.dft(false);
					i++;
					continue;
				}

				else if(arguments[i + 1] == "dft"){
					i++;
					continue;
				}

				else
					return false;

			}

			else
				return false;

		}

		else if(arguments[i] == "-i" || arguments[i] == "--input"){

			if(i + 1 < argc){
				program.newInFile(arguments[i + 1]);
				i++;	
			}

		}

		else if(arguments[i] == "-o" || arguments[i] == "--output"){

			if(i + 1 < argc){
				program.newOutFile(arguments[i + 1]);
				i++;
			}

		}

		else{
			cout << "No se reconoce el argumento" << endl;
			return false;
		}

	}
	
	return true;

}

bool displayHelp(){

	ifstream helpFile(HELP_FILE);

	if(helpFile.is_open()){
		cout << helpFile.rdbuf();
		helpFile.close();
		return true;
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

