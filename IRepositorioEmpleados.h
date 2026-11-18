#ifndef IREPOSITORIOEMPLEADOS_H
#define IREPOSITORIOEMPLEADOS_H
#include "ListaEmpleados.h"
#include "Empleado.h"

class IRepositorioEmpleados {
public:
	virtual ~IRepositorioEmpleados() {}
	virtual void guardarTodos(ListaEmpleados&) = 0;
	virtual void cargarTodos(ListaEmpleados&) = 0;
};

#endif
