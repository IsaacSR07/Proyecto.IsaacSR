#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include <sstream>
#include "Puesto.h"
#include "ListaPuestos.h"

using namespace std;

class Departamento {
private:
	int id;
	string nombre;
	int idJefe;
	ListaPuestos puestos;   // composicion: los Puesto viven y mueren con el Departamento
public:
	Departamento(int, string, int);
	~Departamento();
	void agregarPuesto(int, string, string);
	bool eliminarPuesto(int);
	Puesto* buscarPuesto(int);
	ListaPuestos& getPuestos();
	int getId();
	string getNombre();
	int getIdJefe();
	void setIdJefe(int);
	string serializar();
};

#endif
