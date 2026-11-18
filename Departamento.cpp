#include "Departamento.h"

Departamento::Departamento(int i, string nom, int jefe) {
	id = i;
	nombre = nom;
	idJefe = jefe;
}

Departamento::~Departamento() {}   // ListaPuestos libera los puestos (composicion)

void Departamento::agregarPuesto(int idPuesto, string nom, string desc) {
	puestos.agregarAlFinal(new Puesto(idPuesto, nom, desc));
}

bool Departamento::eliminarPuesto(int idPuesto) {
	return puestos.eliminarPorId(idPuesto);
}

Puesto* Departamento::buscarPuesto(int idPuesto) {
	return puestos.buscarPorId(idPuesto);
}

ListaPuestos& Departamento::getPuestos() { return puestos; }
int Departamento::getId() { return id; }
string Departamento::getNombre() { return nombre; }
int Departamento::getIdJefe() { return idJefe; }
void Departamento::setIdJefe(int jefe) { idJefe = jefe; }

// Una linea "D|..." con el departamento y una linea "P|..." por cada puesto
string Departamento::serializar() {
	stringstream s;
	s << "D|" << id << "|" << nombre << "|" << idJefe;
	for (int i = 0; i < puestos.tamanio(); i++) {
		s << endl << puestos.obtener(i)->serializar();
	}
	return s.str();
}
