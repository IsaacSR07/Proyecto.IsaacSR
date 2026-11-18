#include "ControladorDepartamentos.h"

ControladorDepartamentos::ControladorDepartamentos(IRepositorioDepartamentos& repo) : repositorio(repo) {}

ControladorDepartamentos::~ControladorDepartamentos() {}   // la lista libera sus objetos

void ControladorDepartamentos::cargar() {
	departamentos.limpiar();
	repositorio.cargarTodos(departamentos);
}

void ControladorDepartamentos::guardar() {
	repositorio.guardarTodos(departamentos);
}

bool ControladorDepartamentos::registrar(Departamento* x) {
	if (x == NULL || buscarPorId(x->getId()) != NULL) {
		return false;
	}
	departamentos.agregarAlFinal(x);
	guardar();
	return true;
}

Departamento* ControladorDepartamentos::buscarPorId(int id) {
	return departamentos.buscarPorId(id);
}

bool ControladorDepartamentos::eliminar(int id) {
	if (departamentos.eliminarPorId(id)) {
		guardar();
		return true;
	}
	return false;
}

ListaDepartamentos& ControladorDepartamentos::getDepartamentos() {
	return departamentos;
}
