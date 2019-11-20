#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include <iostream>
#include "Signal.h"

using namespace std;

class Status {
	string inFile, outFile;
	bool help, transform, fast, iterative;

public:
	//Builders
	Status();
	~Status();

	//Status
	bool getMethod();
	bool getSpeed();
	bool getIterative();
	bool stdIn();
	bool stdOut();
	string & getInFile();
	string & getOutFile();
	bool isMethodSet();

	//Modifiers
	void newInFile(string &);
	void newOutFile(string &);
	void setDFT(bool);
	void setFFT(bool);
	void setITER(bool);
	void setHelp();
	bool needHelp();
	void configureSignal(Signal &);
};

#endif
