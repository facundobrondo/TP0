#include <Processing.h>

void loadInputFile(Array<Signal> &signals, istream &is, bool dft) {
	Array<Complex> temp_vcomp;
	Signal temp_sig;
	string temp_line, cell;
	Complex sample;
	bool corrupted_data;
	
	while (std::getline(is, temp_line, '\n')) {
		eraseCarriageReturn(temp_line);
		convertTabToSpace(temp_line);
		eraseUnnecessarySpaces(temp_line, ',');
		
		// verificar archivo vacio
		
		stringstream temp_ss_values(temp_line);
		
		while (getline(temp_ss_values, cell, ' ')) {
			stringstream temp_cell(cell);
		
			if (!(temp_cell >> sample)) {
				corrupted_data = true;
				break;
			}
			
			temp_vcomp.push_back(sample);
			
		}
		
		if (!corrupted_data) {
			if (dft)
				temp_sig.loadTimeSignal(temp_vcomp);
			else
				temp_sig.loadFrecSignal(temp_vcomp);
		} else {
			temp_sig.setCorrupted();
		}
		
		signals.push_back(temp_sig);
	}
	return;
}

void printSignals(Array<Signal> &signals, ostream &os, bool dft) {
	if (dft) {
		for (int i = 0; i < signals.size(); i++) {
			if (signals[i].isCorrupted()) {
				cout << "Corrupted Signal\n";
				continue;
			}
			int j;
			for (j = 0; j < (signals[i].lenght() - 1); j++) {
				os << signals[i].viewFrecSample(j) << ' ';
			}
			os << signals[i].viewFrecSample(j) << '\n';
		}
	} else {
		for (int i = 0; i < signals.size(); i++) {
			if (signals[i].isCorrupted()) {
				cout << "Corrupted Signal\n";
				continue;
			}
			int j;
			for (j = 0; j < (signals[i].lenght() - 1); j++) {
				os << signals[i].viewFrecSample(j) << ' ';
			}
			os << signals[i].viewFrecSample(j) << '\n';
		}	
	}

	os << endl;
	
	return;
}

void processSignals(std::istream &is, std::ostream &os, bool dft) {
	Array<Signal> signals;
	
	//En signals cargar las señales del archivo de entrada según sea temp o frec
	loadInputFile(signals, is, dft);
	cout << "hasta aca\n";
	if (dft) {
		for (int i = 0; i < signals.size() - 1; i++) {
			signals[i].dft();
			cout << "hasta aca\n";
		}
	} else {
		for (int i = 0; i < signals.size() - 1; i++) {
			signals[i].idft();
		}
	}
			cout << "hasta aca\n";
	printSignals(signals, os, dft);
}
