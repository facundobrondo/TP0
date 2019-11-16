#include "main.h"

using namespace std;

int main(int argc, char *argv[]){

	//Se crea un objeto de tipo Status para configurar como se debera ejecutar el programa.

	Status program;
	fstream input, output; 
	Signal inSignal;

	//Se procesan los argumentos recibidos por linea de comandos y se settea program.
	//Si falla se pregunta por ayuda, y sino se muestra un mensaje de error.

	if(!argumentProcessing(argc, argv, program)){

		if(program.needHelp())
			displayHelp();
		else
			displayError();

		return 1;

	}

	//Se settea el objeto de entrada y salida a utilizar, dependiendo de la forma de ejecucion especificada anteriormente.
	//Se puede elegir entre output: stdout o archivo de texto; input: stdin o archivo de texto.

	istream &is = setInStream(program, input);
	ostream &os = setOutStream(program, output);

	//Se settea el metodo a aplicar dentro de un atributo de Signal.
	
	if(program.dft())
		inSignal.setMethod(DFT);

	else
		inSignal.setMethod(IDFT);	


	//Se aplica el proceso de fourier.
	//Se toma un vector, se transforma (dft o idft) y se saca por os.
	//Seguira ejecutandose de esa forma hasta no haber mas vectores.

	inSignal.fourierProcess(is, os);

	//Si se abrieron archivos, se cierran.

	if(input.is_open())
		input.close();

	if(output.is_open())
		output.close();	

	return 0;
}


