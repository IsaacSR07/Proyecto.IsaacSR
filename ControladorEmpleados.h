#ifndef CONTROLADOREMPLEADOS_H
#define CONTROLADOREMPLEADOS_H
#include <iostream>
#include "ListaEmpleados.h"
#include "Empleado.h"
#include "IRepositorioEmpleados.h"

using namespace std;

class ControladorEmpleados {
private:
	ListaEmpleados empleados;
	IRepositorioEmpleados& repositorio;
public:
	ControladorEmpleados(IRepositorioEmpleados&);
	~ControladorEmpleados();
	void cargar();
	void guardar();
	bool registrar(Empleado*);
	Empleado* buscarPorId(int);
	bool actualizarSalario(int, double);
	bool eliminar(int);
	ListaEmpleados& getEmpleados();
};

#endif
