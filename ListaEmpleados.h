#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
#include "Empleado.h"

using namespace std;

/*
 Lista enlazada simple de Empleado*.
 La lista es duena de los empleados: los libera en limpiar() y en el destructor.
*/
class ListaEmpleados {
private:
	Nodo<Empleado*>* cabeza;
	Nodo<Empleado*>* cola;
	int cantidad;
	ListaEmpleados(const ListaEmpleados&);              // copia deshabilitada
	ListaEmpleados& operator=(const ListaEmpleados&);   // copia deshabilitada
public:
	ListaEmpleados();
	~ListaEmpleados();
	void agregarAlFinal(Empleado*);
	Empleado* obtener(int);
	Empleado* buscarPorId(int);
	bool eliminarPorId(int);
	int tamanio();
	bool estaVacia();
	void limpiar();
};

#endif
