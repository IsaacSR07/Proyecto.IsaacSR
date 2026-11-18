#include "ControladorPlanilla.h"

ControladorPlanilla::ControladorPlanilla(IRepositorioPlanilla& repo, ControladorEmpleados& ce,
										 ControladorDepartamentos& cd, CalculadoraSalario& calc)
	: repositorio(repo), ctrlEmpleados(ce), ctrlDepartamentos(cd), calculadora(calc) {}

// Solo libera los comprobantes: los empleados y departamentos pertenecen a sus controladores
ControladorPlanilla::~ControladorPlanilla() {}   // la lista libera sus objetos

void ControladorPlanilla::cargar() {
	comprobantes.limpiar();
	repositorio.cargarTodos(comprobantes, ctrlEmpleados, ctrlDepartamentos);
}

void ControladorPlanilla::guardar() {
	repositorio.guardarTodos(comprobantes);
}

/*
 Genera, agrega y guarda el comprobante de un empleado. Devuelve NULL si el
 empleado o su departamento no existen, o si ya tiene un pago en esa fecha.
*/
ComprobantePago* ControladorPlanilla::procesarPago(int idEmpleado, string fecha) {
	Empleado* emp = ctrlEmpleados.buscarPorId(idEmpleado);
	if (emp == NULL) {
		return NULL;
	}
	Departamento* dep = ctrlDepartamentos.buscarPorId(emp->getIdDepartamento());
	if (dep == NULL) {
		return NULL;
	}
	int nuevoId = 1;
	for (int i = 0; i < comprobantes.tamanio(); i++) {
		ComprobantePago* c = comprobantes.obtener(i);
		if (c->getEmpleado()->getId() == idEmpleado && c->getFecha() == fecha) {
			return NULL;
		}
		if (c->getIdComprobante() >= nuevoId) {
			nuevoId = c->getIdComprobante() + 1;
		}
	}
	double bruto = emp->calcularSalarioBruto();
	double bonificaciones = emp->calcularBonificaciones();
	double deducciones = calculadora.calcularDeducciones(bruto + bonificaciones);
	ComprobantePago* comprobante = new ComprobantePago(nuevoId, emp, dep, fecha, bruto, bonificaciones, deducciones);
	comprobantes.agregarAlFinal(comprobante);
	guardar();
	return comprobante;
}

int ControladorPlanilla::procesarPlanillaCompleta(string fecha) {
	int procesados = 0;
	ListaEmpleados& empleados = ctrlEmpleados.getEmpleados();
	for (int i = 0; i < empleados.tamanio(); i++) {
		if (procesarPago(empleados.obtener(i)->getId(), fecha) != NULL) {
			procesados++;
		}
	}
	return procesados;
}

ListaComprobantes& ControladorPlanilla::getComprobantes() {
	return comprobantes;
}
