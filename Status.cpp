#include "Status.h"

//Builders----------------------------------------

Status::Status(){
	inFile = "";
	outFile = "";
	transform = true;
	fast = true;
	help = false;
	iterative = false;
	inplace = false;
}

Status::~Status(){}

//Status----------------------------------------

bool Status::getMethod(){
	return transform;
}

bool Status::getSpeed(){
	return fast;
}

bool Status::getInPlace(){
	return inplace;
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

			else if (inplace)
				sig.setMethod(IPFFT);

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

			else if(inplace)
				sig.setMethod(IPIFFT);

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

void Status::setIP(bool state){
	inplace = state;
}

void Status::setFFT(bool state){
	fast = state;	
}

void Status::setITER(bool state){
	iterative = state;
}

void Status::setHelp(){
	help = true;
}

bool Status::needHelp(){
	return help;
}
