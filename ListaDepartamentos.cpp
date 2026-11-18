#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos() {
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}

ListaDepartamentos::~ListaDepartamentos() {
	limpiar();
}

void ListaDepartamentos::agregarAlFinal(Departamento* dato) {
	Nodo<Departamento*>* nuevo = new Nodo<Departamento*>(dato);
	if (cabeza == NULL) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->sig = nuevo;
		cola = nuevo;
	}
	cantidad++;
}

Departamento* ListaDepartamentos::obtener(int indice) {
	if (indice < 0 || indice >= cantidad) {
		throw out_of_range("Indice fuera de rango");
	}
	Nodo<Departamento*>* actual = cabeza;
	for (int i = 0; i < indice; i++) {
		actual = actual->sig;
	}
	return actual->dato;
}

Departamento* ListaDepartamentos::buscarPorId(int id) {
	Nodo<Departamento*>* actual = cabeza;
	while (actual != NULL) {
		if (actual->dato->getId() == id) {
			return actual->dato;
		}
		actual = actual->sig;
	}
	return NULL;
}

// Desenlaza el nodo, libera el objeto y libera el nodo
bool ListaDepartamentos::eliminarPorId(int id) {
	Nodo<Departamento*>* anterior = NULL;
	Nodo<Departamento*>* actual = cabeza;
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

int ListaDepartamentos::tamanio() {
	return cantidad;
}

bool ListaDepartamentos::estaVacia() {
	return (cabeza == NULL) ? true : false;
}

void ListaDepartamentos::limpiar() {
	Nodo<Departamento*>* actual = cabeza;
	while (actual != NULL) {
		Nodo<Departamento*>* temporal = actual;
		actual = actual->sig;
		delete temporal->dato;
		delete temporal;
	}
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}
