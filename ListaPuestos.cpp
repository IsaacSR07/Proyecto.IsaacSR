#include "ListaPuestos.h"

ListaPuestos::ListaPuestos() {
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}

ListaPuestos::~ListaPuestos() {
	limpiar();
}

void ListaPuestos::agregarAlFinal(Puesto* dato) {
	Nodo<Puesto*>* nuevo = new Nodo<Puesto*>(dato);
	if (cabeza == NULL) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->sig = nuevo;
		cola = nuevo;
	}
	cantidad++;
}

Puesto* ListaPuestos::obtener(int indice) {
	if (indice < 0 || indice >= cantidad) {
		throw out_of_range("Indice fuera de rango");
	}
	Nodo<Puesto*>* actual = cabeza;
	for (int i = 0; i < indice; i++) {
		actual = actual->sig;
	}
	return actual->dato;
}

Puesto* ListaPuestos::buscarPorId(int id) {
	Nodo<Puesto*>* actual = cabeza;
	while (actual != NULL) {
		if (actual->dato->getId() == id) {
			return actual->dato;
		}
		actual = actual->sig;
	}
	return NULL;
}

// Desenlaza el nodo, libera el objeto y libera el nodo
bool ListaPuestos::eliminarPorId(int id) {
	Nodo<Puesto*>* anterior = NULL;
	Nodo<Puesto*>* actual = cabeza;
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

int ListaPuestos::tamanio() {
	return cantidad;
}

bool ListaPuestos::estaVacia() {
	return (cabeza == NULL) ? true : false;
}

void ListaPuestos::limpiar() {
	Nodo<Puesto*>* actual = cabeza;
	while (actual != NULL) {
		Nodo<Puesto*>* temporal = actual;
		actual = actual->sig;
		delete temporal->dato;
		delete temporal;
	}
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}
