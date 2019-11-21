#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

#include "cmdline.h"
#include "Complex.h"
#include "Signal.h"

using namespace std;

static void opt_reference(string const &);
static void opt_output(string const &);
static void opt_tolerance(string const &);
static void opt_help(string const &);

static option_t options[] = {
	{1, "r", "reference", NULL, opt_reference, OPT_MANDATORY},
	{1, "o", "output", NULL, opt_output, OPT_MANDATORY},
	{1, "t", "tolerance", "1E-5", opt_tolerance, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *rss = 0;
static istream *oss = 0;
static double tolerance;
static fstream rfs;
static fstream ofs;

static void opt_reference(string const &arg) {
	rfs.open(arg.c_str(), ios::in);
	rss = &rfs;
	
	if (!rss->good()) {
		cerr << "Cannot open " << arg << "." << endl;
		exit(1);
	}
}

static void opt_output(string const &arg) {
	ofs.open(arg.c_str(), ios::in);
	oss = &ofs;

	if (!oss->good()) {
		cerr << "Cannot open " << arg << "." << endl;
		exit(1);
	}
}

static void opt_tolerance(string const &arg) {
	istringstream iss(arg);

	if (!(iss >> tolerance) || !iss.eof()) {
		cerr << "Non-number: " << arg << "." << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "Cannot read tolerance." << endl;
		exit(1);
	}
	
	if (tolerance < 0.0) {
		cerr << "Invalid tolerance: " << arg << "." << endl;
		exit(1);	
	}
}

static void opt_help(string const &arg) {
	cout << "cmdline [-r file] [-o file] [-t number]" << endl;
	exit(0);
}

////////////////////////////////////////////////////////////////////////////////

// Main function.
int main(int argc, char * const argv[]) {
	//Parser command line arguments.
	cmdline cmdl(options);
	cmdl.parse(argc, argv);

	string temp_rline, temp_oline;
	Signal ref_signal, out_signal;
	
	size_t counter_file_line = 1;
	//Reads lines of references files.
	while (getline(*rss, temp_rline, '\n')) {
		//Read a line of output files.
		getline(*oss, temp_oline, '\n');
		char _c =  temp_rline.front();
		
		//Use char '(' like indicator of valid line.
		if (_c != '(') {
			counter_file_line++;
			continue;
		}
		
		//Convert line to signal.
		stringstream temp_rss(temp_rline);
		stringstream temp_oss(temp_oline);
		
		temp_rss >> ref_signal;
		temp_oss >> out_signal;
		
		//Compare reference and output signal
		for (size_t count = 0; count <= ref_signal.getInput().getSize(); count++) {
			Complex ref_cmplx((ref_signal.getInput())[count]);
			Complex out_cmplx((out_signal.getInput())[count]);
			
			if (tolerance >= abs((ref_cmplx.Re() - out_cmplx.Re()))) {
				if (tolerance >= abs((ref_cmplx.Im() - out_cmplx.Im()))) {
					continue;
				}
			}
			
			//Print error location.
			cerr << "Diff in line " << counter_file_line;
			cerr << " in sample " << (count + 1) << endl;
			return EXIT_FAILURE;
		}
		
		temp_rline.clear();
		temp_oline.clear();
		counter_file_line++;
	}
	
	return EXIT_SUCCESS;
}
