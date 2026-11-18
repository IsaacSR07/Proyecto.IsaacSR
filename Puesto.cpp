#include "Puesto.h"

Puesto::Puesto(int i, string nom, string desc) {
	id = i;
	nombre = nom;
	descripcion = desc;
}

Puesto::~Puesto() {}

int Puesto::getId() { return id; }
string Puesto::getNombre() { return nombre; }
string Puesto::getDescripcion() { return descripcion; }

string Puesto::serializar() {
	stringstream s;
	s << "P|" << id << "|" << nombre << "|" << descripcion;
	return s.str();
}
