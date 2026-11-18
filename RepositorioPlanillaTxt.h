#ifndef REPOSITORIOPLANILLATXT_H
#define REPOSITORIOPLANILLATXT_H
#include <iostream>
#include <fstream>
#include "IRepositorioPlanilla.h"

using namespace std;

class RepositorioPlanillaTxt : public IRepositorioPlanilla {
private:
	string rutaArchivo;
public:
	RepositorioPlanillaTxt(string);
	void guardarTodos(ListaComprobantes&) override;
	void cargarTodos(ListaComprobantes&, ControladorEmpleados&, ControladorDepartamentos&) override;
};

#endif
