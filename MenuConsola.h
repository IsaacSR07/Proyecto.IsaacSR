#ifndef MENUCONSOLA_H
#define MENUCONSOLA_H
#include <iostream>
#include "ControladorEmpleados.h"
#include "ControladorDepartamentos.h"
#include "ControladorPlanilla.h"

using namespace std;

class MenuConsola {
private:
	ControladorEmpleados& ctrlEmpleados;
	ControladorDepartamentos& ctrlDepartamentos;
	ControladorPlanilla& ctrlPlanilla;
	void menuEmpleados();
	void menuDepartamentos();
	void menuPlanilla();
	int leerEntero(string);
	double leerDecimal(string);
	string leerTexto(string);
	void mostrarMensaje(string);
public:
	MenuConsola(ControladorEmpleados&, ControladorDepartamentos&, ControladorPlanilla&);
	void ejecutar();
};

#endif
