#include "Status.h"

Status::Status(){

	inFile = "";
	outFile = "";
	discreteFourierTransform = true;
	help = false; //hay que cambiar??

}

Status::~Status(){}

bool Status::dft(){
	return discreteFourierTransform;
}

bool Status::stdIn(){
	return inFile.empty();
}

bool Status::stdOut(){
	return outFile.empty();
}

string & Status::getOutFile(){
	return outFile;
}

string & Status::getInFile(){
	return inFile;
}

void Status::newInFile(string &iF){
	inFile += iF;
}

void Status::newOutFile(string &oF){
	outFile += oF;
}

void Status::dft(bool state){
	discreteFourierTransform = state;
}

void Status::setHelp(){
	help = true;
}

bool Status::needHelp(){
	return help;
}
