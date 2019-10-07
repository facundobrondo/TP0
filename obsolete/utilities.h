#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED

#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

// Borra los espacios innecesarios en una línea CSV.
void eraseUnnecessarySpaces(string &, char);

// Elimina el retorno de carro de un string.
void eraseCarriageReturn(string &);

// Convierte tabulaciones en espacios.
void convertTabToSpace(string &);

#endif
