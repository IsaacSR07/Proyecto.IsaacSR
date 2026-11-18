#include "ListaComprobantes.h"

ListaComprobantes::ListaComprobantes() {
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}

ListaComprobantes::~ListaComprobantes() {
	limpiar();
}

void ListaComprobantes::agregarAlFinal(ComprobantePago* dato) {
	Nodo<ComprobantePago*>* nuevo = new Nodo<ComprobantePago*>(dato);
	if (cabeza == NULL) {
		cabeza = nuevo;
		cola = nuevo;
	} else {
		cola->sig = nuevo;
		cola = nuevo;
	}
	cantidad++;
}

ComprobantePago* ListaComprobantes::obtener(int indice) {
	if (indice < 0 || indice >= cantidad) {
		throw out_of_range("Indice fuera de rango");
	}
	Nodo<ComprobantePago*>* actual = cabeza;
	for (int i = 0; i < indice; i++) {
		actual = actual->sig;
	}
	return actual->dato;
}

int ListaComprobantes::tamanio() {
	return cantidad;
}

bool ListaComprobantes::estaVacia() {
	return (cabeza == NULL) ? true : false;
}

void ListaComprobantes::limpiar() {
	Nodo<ComprobantePago*>* actual = cabeza;
	while (actual != NULL) {
		Nodo<ComprobantePago*>* temporal = actual;
		actual = actual->sig;
		delete temporal->dato;
		delete temporal;
	}
	cabeza = NULL;
	cola = NULL;
	cantidad = 0;
}
