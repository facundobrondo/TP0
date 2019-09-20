#include "CommandLineArguments.h"

const char flags[][MAX_LEN] = {HELP1, HELP2, METHOD1, METHOD2, INPUT1, INPUT2, OUTPUT1, OUTPUT2};

bool argumentProcessing(size_t argc, char *argv[], Status &program){

	//Default set
	if(argc == 1)
		return true;

	Array<string> arguments(argc);
	char2stringArray(argc, argv, arguments);

	bool met = false, in = false, out = false;
	bool st = true;

	//Display Help
	if(arguments[1] == "-h" || arguments[1] == "--help"){
		program.setHelp();
		return false;
	}

	// Arguments process
	for(size_t i = 1; i < argc; i++){

		if(arguments[i] == "-m" || arguments[i] == "--method"){

			if(program.isMethodSet())
				return false;
			
			program.methodSet();

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

		else if(arguments[i] == "-i" || arguments[i] == "--input"){

			if(program.isInputSet())
				return false;

			program.inputSet();

			if(isFlag(arguments[i + 1]))
				return false;

			if(i + 1 < argc){
				program.newInFile(arguments[i + 1]);
				i++;
				continue;
			}

			else
				return false;

		}

		else if(arguments[i] == "-o" || arguments[i] == "--output"){

			if(program.isOutputSet())
				return false;

			program.outputSet();

			if(isFlag(arguments[i + 1]))
				return false;

			if(i + 1 < argc){
				program.newOutFile(arguments[i + 1]);
				i++;
				continue;
			}

			else
				return false;

		}

		else
			return false;

	}

	return true;

}

bool displayHelp(){

	ifstream helpFile(HELP_FILE);

	if(helpFile.is_open()){

		cout << helpFile.rdbuf() << endl;
		helpFile.close();
		return true;

	}

	return false;

}

bool displayError(){

	ifstream errorFile(ERROR_FILE);

	if(errorFile.is_open()){

		cout << errorFile.rdbuf() << endl;
		errorFile.close();
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

bool isFlag(string s){

	size_t nFlags = sizeof(flags) / sizeof(flags[1]);

	for(size_t i = 0; i < nFlags; i++)
		if(s == flags[i])
			return true;

	return false;

}
