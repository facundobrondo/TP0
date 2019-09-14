#include <iostream>
#include "Array.h"

using namespace std;

int main(void){

	size_t i;
	Array <int> a(10);
	Array <int> b(8);

	cout << "Comienzo prueba concatenar arreglos" << endl;

	for(i = 0; i < a.getSize(); i++)
		a[i] = i;

	for(i = 0; i < b.getSize(); i++)
		b[i] = i * 3;

	for(i = 0; i < a.getSize(); i++)
		cout << a[i] << ' ';

	cout << endl << "-----" << endl;

	for(i = 0; i < b.getSize(); i++)
		cout << b[i] << ' ';

	cout << endl << "-----" << endl;

	a += b;

	for(i = 0; i < a.getSize(); i++)
		cout << a[i] << ' ';

	cout << endl << "-----" << endl;

	cout << "Fin prueba concatenar arreglos" << endl;

	cout << "Inicio prueba agregar elementos" << endl;


	int dato = 100;

	a += dato;

	for(i = 0; i < a.getSize(); i++)
		cout << a[i] << ' ';

	cout << endl << "-----" << endl;

	cout << "Fin prueba agregar elemento" << endl;

	cout << "Inicio prueba impresion arreglo" << endl;

	cout << a;

	cout << "Fin prueba impresion arreglo" << endl;

	return 0;

}	
