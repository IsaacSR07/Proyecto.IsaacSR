#ifndef LISTADEDUCCIONES_H
#define LISTADEDUCCIONES_H
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
#include "IDeduccion.h"

using namespace std;

/*
 Lista enlazada simple de IDeduccion*.
 La lista es duena de los objetos IDeduccion: los libera en limpiar() y en el destructor.
*/
class ListaDeducciones {
private:
	Nodo<IDeduccion*>* cabeza;
	Nodo<IDeduccion*>* cola;
	int cantidad;
	ListaDeducciones(const ListaDeducciones&);              // copia deshabilitada
	ListaDeducciones& operator=(const ListaDeducciones&);   // copia deshabilitada
public:
	ListaDeducciones();
	~ListaDeducciones();
	void agregarAlFinal(IDeduccion*);
	IDeduccion* obtener(int);
	int tamanio();
	bool estaVacia();
	void limpiar();
};

#endif
