#include "Status.h"

//Builders----------------------------------------

Status::Status(){
	inFile = "";
	outFile = "";
	transform = true;
	fast = false;
	help = false;
	iterative = false;
}

Status::~Status(){}

//Status----------------------------------------

bool Status::getMethod(){
	return transform;
}

bool Status::getSpeed(){
	return fast;
}

bool Status::getIterative(){
	return iterative;
}

bool Status::stdIn(){
	return inFile.empty();
}

bool Status::stdOut(){
	return outFile.empty();
}

string & Status::getInFile(){
	return inFile;
}

string & Status::getOutFile(){
	return outFile;
}

//Modifiers------------------------------------

void Status::configureSignal(Signal &sig){

	if(transform){

		if(fast){

			if(iterative)
				sig.setMethod(ITFFT);

			else
				sig.setMethod(FFT);

		}

		else
			sig.setMethod(DFT);

	}

	else{

		if(fast){

			if(iterative)
				sig.setMethod(ITIFFT);

			else
				sig.setMethod(IFFT);

		}

		else
			sig.setMethod(IDFT);

	}

}

void Status::newInFile(string &iF){
	inFile += iF;
}

void Status::newOutFile(string &oF){
	outFile += oF;
}

void Status::setDFT(bool state){
	transform = state;
}

void Status::setFFT(bool state){
	fast = state;	
}

void Status::setHelp(){
	help = true;
}

bool Status::needHelp(){
	return help;
}
