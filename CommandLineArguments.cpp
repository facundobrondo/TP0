#include "CommandLineArguments.h"

//Se crea un arreglo de strings para guardar todos los argumentos posibles.
const char flags[][MAX_LEN] = {METHOD1, METHOD2, INPUT1, INPUT2, OUTPUT1, OUTPUT2, HELP1, HELP2};

//Se crea un arreglo de punteros a funciones para guardar las "acciones" a realizar por cada par de argumentos.
bool (*f[OPTIONS])(Status &, string &) = {processMethod, processInput, processOutput};

bool argumentProcessing(size_t argc, char *argv[], Status &program){

	//Se convierten los argumentos en argv a un arreglo de objetos strings para mejor uso mediante los metodos de la
	//clase string.

	Array<string> arguments(argc);
	char2stringArray(argc, argv, arguments);

	if(isHelp(arguments[1])){
		program.setHelp();
		return false;
	}

	for(size_t i = 1; i < argc; i += 2){

		size_t index = isFlag(arguments[i]) + 1;

		if (index && i + 1 < argc)
			if (!f[index / 2](program, arguments[i + 1]))
				return false;

	}	
	
	return true;

}

bool processMethod(Status &program, string &option){

	if(option == IDFT)
		program.setDFT(false);

	else if(option == DFT || option == STANDARD)
		program.setDFT(true);

	else if(option == FFT){
		program.setDFT(true);
		program.setFFT(true);
	}

	else if (option == IFFT){
		program.setDFT(false);
		program.setFFT(true);
	}

	else
		return false;

	return true;

}

bool processInput(Status &program, string &option){

	if(option == STANDARD)
		return true;

	if(isFlag(option))
		return false;

	program.newInFile(option);

	return true;

}

bool processOutput(Status &program, string &option){

	if(option == STANDARD)
		return true;

	if(isFlag(option))
		return false;

	program.newOutFile(option);

	return true;

}

bool displayHelp(){

	ifstream helpFile(HELP_FILE);

	if (helpFile.is_open()){

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

	for (i = 0; string[i] != '\0'; i++);

	return i;

}

void convert2string(size_t length, char cArray[], string &str){

	str = "";

	for (size_t i = 0; i < length; i++)
		str = str + cArray[i];

}

size_t isFlag(string s){

	size_t nFlags = sizeof(flags) / sizeof(flags[1]);

	for(size_t i = 0; i < nFlags; i++)
		if(s == flags[i])
			return i;

	return 0;

}

bool isHelp(string s){

	size_t nFlags = sizeof(flags) / sizeof(flags[1]);

	for(size_t i = 0; i < nFlags; i++)
		if(s == HELP1 || s == HELP2)
			return true;

	return false;
	
}
