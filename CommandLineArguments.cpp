#include "CommandLineArguments.h"

bool argumentProcessing(size_t argc, char *argv[], Status &program){

	if (argc == 1) // default set
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

			if (met == true){ // method has already been set
				st = false;
				break;
			}
			met = true;

		    if(arguments[i + 1] == "idft"){
				program.dft(false);
				i++;
				continue;
			}
			else if(arguments[i + 1] == "dft"){
				i++;
				continue;
			}
			else{
				st = false;
				break;
			}

		}

		else if(arguments[i] == "-i" || arguments[i] == "--input"){

			if (in == true ){
				st = false;
				break;
			} //input has already been set
			in = true;

			if (arguments[i + 1] == "-i"
			||  arguments[i + 1] == "-o"
			||  arguments[i + 1] == "-m"){ // palabras reservadas
				st = false;
				break;
			}

			if(i + 1 < argc){
				program.newInFile(arguments[i + 1]);
				i++;
				continue;
			}
			else{
				st = false;
				break;
			}
		}

		else if(arguments[i] == "-o" || arguments[i] == "--output"){

			if (out == true){
				st = false;
				break;
			} //onput has already been set
			out = true;

			if (arguments[i + 1] == "-i"
			||  arguments[i + 1] == "-o"
			||  arguments[i + 1] == "-m"){ // palabras reservadas
				st = false;
				break;
			}


			if(i + 1 < argc){
				program.newOutFile(arguments[i + 1]);
				i++;
				continue;
			}
			else{
				st = false;
				break;
			}
		}
		else{
			st = false;
			break;
		}
	}

	if (st == false){
		cout << "Error al invocar el programa" << endl;
		cout << "Para mas informacion intente: -h ó --help" << endl;
		return false;
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
