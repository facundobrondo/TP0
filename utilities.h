// Utilidades.

#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <string>
#include <cstdlib>
#include <cstring>

// Borra los espacios innecesarios en una línea CSV.
void eraseUnnecessarySpaces(std::string &, char);
// Elimina el retorno de carro de un string.
void eraseCarriageReturn(std::string &);
// Convierte tabulaciones en espacios.
void convertTabToSpace(std::string &);

#endif
