#ifndef LISTAPUESTOS_H
#define LISTAPUESTOS_H
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
#include "Puesto.h"

using namespace std;

/*
 Lista enlazada simple de Puesto*.
 La lista es duena de los puestos: los libera en limpiar() y en el destructor.
*/
class ListaPuestos {
private:
	Nodo<Puesto*>* cabeza;
	Nodo<Puesto*>* cola;
	int cantidad;
	ListaPuestos(const ListaPuestos&);              // copia deshabilitada
	ListaPuestos& operator=(const ListaPuestos&);   // copia deshabilitada
public:
	ListaPuestos();
	~ListaPuestos();
	void agregarAlFinal(Puesto*);
	Puesto* obtener(int);
	Puesto* buscarPorId(int);
	bool eliminarPorId(int);
	int tamanio();
	bool estaVacia();
	void limpiar();
};

#endif
