#ifndef LISTADEPARTAMENTOS_H
#define LISTADEPARTAMENTOS_H
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
#include "Departamento.h"

using namespace std;

/*
 Lista enlazada simple de Departamento*.
 La lista es duena de los departamentos: los libera en limpiar() y en el destructor.
*/
class ListaDepartamentos {
private:
	Nodo<Departamento*>* cabeza;
	Nodo<Departamento*>* cola;
	int cantidad;
	ListaDepartamentos(const ListaDepartamentos&);              // copia deshabilitada
	ListaDepartamentos& operator=(const ListaDepartamentos&);   // copia deshabilitada
public:
	ListaDepartamentos();
	~ListaDepartamentos();
	void agregarAlFinal(Departamento*);
	Departamento* obtener(int);
	Departamento* buscarPorId(int);
	bool eliminarPorId(int);
	int tamanio();
	bool estaVacia();
	void limpiar();
};

#endif
