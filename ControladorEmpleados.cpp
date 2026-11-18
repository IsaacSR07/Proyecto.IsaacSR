#include "ControladorEmpleados.h"

ControladorEmpleados::ControladorEmpleados(IRepositorioEmpleados& repo) : repositorio(repo) {}

ControladorEmpleados::~ControladorEmpleados() {}   // la lista libera sus objetos

void ControladorEmpleados::cargar() {
	empleados.limpiar();
	repositorio.cargarTodos(empleados);
}

void ControladorEmpleados::guardar() {
	repositorio.guardarTodos(empleados);
}

// El controlador se hace dueno del empleado solo si el registro es exitoso
bool ControladorEmpleados::registrar(Empleado* x) {
	if (x == NULL || buscarPorId(x->getId()) != NULL) {
		return false;
	}
	empleados.agregarAlFinal(x);
	guardar();
	return true;
}

Empleado* ControladorEmpleados::buscarPorId(int id) {
	return empleados.buscarPorId(id);
}

bool ControladorEmpleados::actualizarSalario(int id, double nuevoSalario) {
	Empleado* e = buscarPorId(id);
	if (e == NULL) {
		return false;
	}
	e->setSalarioBase(nuevoSalario);
	guardar();
	return true;
}

bool ControladorEmpleados::eliminar(int id) {
	if (empleados.eliminarPorId(id)) {
		guardar();
		return true;
	}
	return false;
}

ListaEmpleados& ControladorEmpleados::getEmpleados() {
	return empleados;
}
