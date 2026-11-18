#ifndef VALIDADOR_H
#define VALIDADOR_H
#include <iostream>

using namespace std;

class Validador {
public:
	static bool esEnteroPositivo(string);
	static bool esDecimalPositivo(string);
	static bool esTextoNoVacio(string);
	static bool esCedulaValida(string);
	static bool esFechaValida(string);
};

#endif
