#ifndef IREPOSITORIOPLANILLA_H
#define IREPOSITORIOPLANILLA_H
#include "ListaComprobantes.h"
#include "ComprobantePago.h"

class ControladorEmpleados;
class ControladorDepartamentos;

class IRepositorioPlanilla {
public:
	virtual ~IRepositorioPlanilla() {}
	virtual void guardarTodos(ListaComprobantes&) = 0;
	virtual void cargarTodos(ListaComprobantes&, ControladorEmpleados&, ControladorDepartamentos&) = 0;
};

#endif
