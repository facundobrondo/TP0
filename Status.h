#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

#include <iostream>

using namespace std;

class Status {
	string inFile, outFile;
	bool help, discreteFourierTransform;

public:
	//Builders
	Status();
	~Status();

	//Status
	bool dft();
	bool stdIn();
	bool stdOut();
	string & getInFile();
	string & getOutFile();
	bool isMethodSet();

	//Modifiers
	void newInFile(string &);
	void newOutFile(string &);
	void dft(bool);
	void setHelp();
	bool needHelp();
};

#endif
