#include "ListaEmpleados.h"

ListaEmpleados::ListaEmpleados() {
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}

ListaEmpleados::~ListaEmpleados() {
	limpiar();
}

void ListaEmpleados::agregarAlFinal(Empleado* dato) {
	Nodo<Empleado*>* nuevo = new Nodo<Empleado*>(dato);
	if (cabeza == NULL) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->sig = nuevo;
		cola = nuevo;
	}
	cantidad++;
}

Empleado* ListaEmpleados::obtener(int indice) {
	if (indice < 0 || indice >= cantidad) {
		throw out_of_range("Indice fuera de rango");
	}
	Nodo<Empleado*>* actual = cabeza;
	for (int i = 0; i < indice; i++) {
		actual = actual->sig;
	}
	return actual->dato;
}

Empleado* ListaEmpleados::buscarPorId(int id) {
	Nodo<Empleado*>* actual = cabeza;
	while (actual != NULL) {
		if (actual->dato->getId() == id) {
			return actual->dato;
		}
		actual = actual->sig;
	}
	return NULL;
}

// Desenlaza el nodo, libera el objeto y libera el nodo
bool ListaEmpleados::eliminarPorId(int id) {
	Nodo<Empleado*>* anterior = NULL;
	Nodo<Empleado*>* actual = cabeza;
	while (actual != NULL && actual->dato->getId() != id) {
		anterior = actual;
		actual = actual->sig;
	}
	if (actual == NULL) {
		return false;
	}
	if (anterior == NULL) {
		cabeza = actual->sig;
	} else {
		anterior->sig = actual->sig;
	}
	if (actual == cola) {
		cola = anterior;
	}
	delete actual->dato;
	delete actual;
	cantidad--;
	return true;
}

int ListaEmpleados::tamanio() {
	return cantidad;
}

bool ListaEmpleados::estaVacia() {
	return (cabeza == NULL) ? true : false;
}

void ListaEmpleados::limpiar() {
	Nodo<Empleado*>* actual = cabeza;
	while (actual != NULL) {
		Nodo<Empleado*>* temporal = actual;
		actual = actual->sig;
		delete temporal->dato;
		delete temporal;
	}
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}
