#ifndef FABRICAEMPLEADO_H
#define FABRICAEMPLEADO_H
#include <iostream>
#include "Empleado.h"

using namespace std;

class FabricaEmpleado {
public:
	static Empleado* crearDesdeRegistro(string);
};

#endif
