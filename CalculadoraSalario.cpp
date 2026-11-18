#include "CalculadoraSalario.h"

CalculadoraSalario::CalculadoraSalario() {}

CalculadoraSalario::~CalculadoraSalario() {}   // ListaDeducciones libera las deducciones

void CalculadoraSalario::agregarDeduccion(IDeduccion* d) {
	deducciones.agregarAlFinal(d);
}

double CalculadoraSalario::calcularDeducciones(double salarioBruto) {
	double total = 0;
	for (int i = 0; i < deducciones.tamanio(); i++) {
		total += deducciones.obtener(i)->calcular(salarioBruto);
	}
	return total;
}

// Salario neto = bruto + bonificaciones - deducciones de ley
double CalculadoraSalario::calcularSalarioNeto(Empleado& e) {
	double bruto = e.calcularSalarioBruto();
	double bonificaciones = e.calcularBonificaciones();
	double deduccionesTotales = calcularDeducciones(bruto + bonificaciones);
	return bruto + bonificaciones - deduccionesTotales;
}
