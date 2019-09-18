#include <iostream>
#include "Array.h"
#include "Complex.h"
#include "Status.h"

using namespace std;

int main(void){

	Status program;

	cout << (program.dft() ? "DFT" : "iDFT") << endl;
	cout << "I:" << program.getInFile() << endl;
	cout << "O:" << program.getOutFile() << endl;
	cout << (program.stdIn() ? "stdin" : "inFile") << endl;
	cout << (program.stdOut() ? "stdout" : "outFile") << endl;

	string iF("pruebaI.txt");
	string oF("pruebaO.txt");

	program.newInFile(iF);
	program.newOutFile(oF);
	cout << "I:" << program.getInFile() << endl;
	cout << "O:" << program.getOutFile() << endl;

	size_t i;
	Array <int> a(10);
	Array <int> b(8);

	cout << "-------------------------- Pruebas Array --------------------------" << endl << endl;

	cout << "Comienzo prueba concatenar arreglos" << endl << endl;

	for(i = 0; i < a.getSize(); i++)
		a[i] = i;

	for(i = 0; i < b.getSize(); i++)
		b[i] = i * 3;

	cout << a << endl;

	cout << "------------------------" << endl << endl;

	cout << b << endl;

	cout << "------------------------" << endl << endl;

	a += b;

	cout << a << endl;

	cout << "------------------------" << endl << endl;

	cout << "Fin prueba concatenar arreglos" << endl << endl;

	cout << "Inicio prueba agregar elementos" << endl << endl;


	int dato = 100;

	a += dato;

	cout << a << endl;

	cout << "-----------------------------" << endl << endl;

	cout << "Fin prueba agregar elemento" << endl << endl;

	cout << "Inicio prueba impresion arreglo" << endl << endl;

	cout << a <<endl;

	cout << "Fin prueba impresion arreglo" << endl << endl;

	cout << "-------------------------- Pruebas Complex --------------------------" << endl << endl ;
	
	cout << "Comienzo prueba crear e imprimir complejos" << endl << endl;

	Complex c1, c2(3), c3(3, 4), c4(c2), c5(1.1, 2.2);

	cout << c1 << endl << c2 << endl << c3 << endl << c4 << endl;

	cout << endl;

	cout << "Status" << endl << endl;

	cout << "Es real (3,0)?: " << (c2.isReal() ? "True" : "False") << endl;
	cout << "Es real (3,4)?: " << (c3.isReal() ? "True" : "False") << endl;

	cout << "Es cero (0,0)?: " << (c1.isZero() ? "True" : "False") << endl;	
	cout << "Es cero (3,0)?: " << (c2.isZero() ? "True" : "False") << endl;

	cout << endl;


	cout << "Operaciones" << endl << endl;

	cout << "Suma entre " << c3 << " y " << c2 << " da:" << c3 + c2 << endl;
	cout << "Resta entre " << c3 << " y " << c2 << " da:" << c3 - c2 << endl;
	cout << "Multiplicacion entre " << c3 << " y " << c5 << " da:" << c3 * c5 << endl;
	cout << "Division entre " << c3 << " y " << c5 << " da:" << c3 / c5 << endl << endl;

	cout << "Operaciones sobre un mismo complejo" << endl <<endl;

	cout << "Suma entre " << c3 << " y " << c5 << " da:";
	c3 += c5;
	cout << c3 << endl;

	cout << "Resta entre " << c3 << " y " << c5 << " da:";
	c3 -= c5;
	cout << c3 << endl;

	cout << "Multiplicacion entre " << c3 << " y " << c5 << " da:";
	c3 *= c5;
	cout << c3 << endl;

	cout << "Division entre " << c3 << " y " << c5 << " da:";
	c3 /= c5;
	cout << c3 << endl << endl;

	cout << "OBS: Estas operaciones incluyen el metodo de modulo y modulo al cuadrado" << endl << endl;

	cout << "Operaciones con numeros reales" << endl << endl;

	cout << "c5 = " << c5 << endl << endl;	

	cout << "c5 + 3: " << c5 + 3 << endl;
	cout << "c5 - 3: " << c5 - 3 << endl;
	cout << "c5 * 3: " << c5 * 3 << endl;
	cout << "c5 / 3: " << c5 / 3 << endl;

	cout << endl;

	cout << "Operaciones sobre c5" << endl << endl;

	cout << "c5 = " << c5 << endl << endl;	

	c5 += 3;
	cout << "c5 += 3: " << c5 << endl;

	c5 -= 3;
	cout << "c5 -= 3: " << c5 << endl;

	c5 *= 3;
	cout << "c5 *= 3: " << c5 << endl;

	c5 /= 3;
	cout << "c5 /= 3: " << c5 << endl;


	cout << endl;

	cout << "Conjugacion sobre el mismo objeto" << endl << endl;

	cout << "OBS: La conjugacion sobre un objeto devuelto por copia se probo implicitamente dado que la division usa ese metodo" << endl << endl;

	cout << "c5 vale: " << c5 << endl;
	c5.conjugateThis();

	cout << "c5 conjugado vale: " << c5 << endl << endl;

	cout << "-------------------------- Pruebas Array con Complex --------------------------" << endl << endl ;

	Array<Complex> CArr(10);

	cout << CArr << endl;

	for(size_t i = 0; i < 10; i++)
		CArr[i] += i;

	cout << CArr << endl;

	return 0;

}	
