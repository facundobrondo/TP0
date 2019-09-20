#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include <iostream>

using namespace std;

class Status{

	string inFile, outFile;
	bool help, discreteFourierTransform;

	bool method, input, output;

public:

	//Builder

	Status();
	~Status();

	//Status

	bool dft();
	bool stdIn();
	bool stdOut();
	string & getOutFile();
	string & getInFile();
	bool isOutputSet();
	bool isInputSet();
	bool isMethodSet();

	//Modifiers

	void newInFile(string &);
	void newOutFile(string &);
	void dft(bool);
	void setHelp();
	bool needHelp();
	void methodSet();
	void inputSet();
	void outputSet();
	void methodCleared();
	void inputCleared();
	void outputCleared();

};

#endif