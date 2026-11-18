#ifndef REPOSITORIOEMPLEADOSTXT_H
#define REPOSITORIOEMPLEADOSTXT_H
#include <iostream>
#include <fstream>
#include "IRepositorioEmpleados.h"

using namespace std;

class RepositorioEmpleadosTxt : public IRepositorioEmpleados {
private:
	string rutaArchivo;
public:
	RepositorioEmpleadosTxt(string);
	void guardarTodos(ListaEmpleados&) override;
	void cargarTodos(ListaEmpleados&) override;
};

#endif
