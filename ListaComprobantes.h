#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
#include "ComprobantePago.h"

using namespace std;

/*
 Lista enlazada simple de ComprobantePago*.
 La lista es duena de los comprobantes (no libera el Empleado ni el Departamento que referencian): los libera en limpiar() y en el destructor.
*/
class ListaComprobantes {
private:
	Nodo<ComprobantePago*>* cabeza;
	Nodo<ComprobantePago*>* cola;
	int cantidad;
	ListaComprobantes(const ListaComprobantes&);              // copia deshabilitada
	ListaComprobantes& operator=(const ListaComprobantes&);   // copia deshabilitada
public:
	ListaComprobantes();
	~ListaComprobantes();
	void agregarAlFinal(ComprobantePago*);
	ComprobantePago* obtener(int);
	int tamanio();
	bool estaVacia();
	void limpiar();
};

#endif
