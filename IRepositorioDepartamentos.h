#ifndef IREPOSITORIODEPARTAMENTOS_H
#define IREPOSITORIODEPARTAMENTOS_H
#include "ListaDepartamentos.h"
#include "Departamento.h"

class IRepositorioDepartamentos {
public:
	virtual ~IRepositorioDepartamentos() {}
	virtual void guardarTodos(ListaDepartamentos&) = 0;
	virtual void cargarTodos(ListaDepartamentos&) = 0;
};

#endif
