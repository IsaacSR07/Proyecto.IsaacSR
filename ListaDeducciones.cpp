#include "ListaDeducciones.h"

ListaDeducciones::ListaDeducciones() {
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}

ListaDeducciones::~ListaDeducciones() {
	limpiar();
}

void ListaDeducciones::agregarAlFinal(IDeduccion* dato) {
	Nodo<IDeduccion*>* nuevo = new Nodo<IDeduccion*>(dato);
	if (cabeza == NULL) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->sig = nuevo;
		cola = nuevo;
	}
	cantidad++;
}

IDeduccion* ListaDeducciones::obtener(int indice) {
	if (indice < 0 || indice >= cantidad) {
		throw out_of_range("Indice fuera de rango");
	}
	Nodo<IDeduccion*>* actual = cabeza;
	for (int i = 0; i < indice; i++) {
		actual = actual->sig;
	}
	return actual->dato;
}

int ListaDeducciones::tamanio() {
	return cantidad;
}

bool ListaDeducciones::estaVacia() {
	return (cabeza == NULL) ? true : false;
}

void ListaDeducciones::limpiar() {
	Nodo<IDeduccion*>* actual = cabeza;
	while (actual != NULL) {
		Nodo<IDeduccion*>* temporal = actual;
		actual = actual->sig;
		delete temporal->dato;
		delete temporal;
	}
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}
