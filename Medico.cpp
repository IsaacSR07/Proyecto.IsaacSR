#include "Medico.h"

Medico::Medico(int i, string nom, string ape, string ced, string fecha, double sal, int idDep, int idPue,
			   string esp, string numCol, int horasG, double pagoG)
	: Empleado(i, nom, ape, ced, fecha, sal, idDep, idPue) {
	especialidad = esp;
	numeroColegiado = numCol;
	horasGuardia = horasG;
	pagoPorGuardia = pagoG;
}

double Medico::calcularSalarioBruto() {
	return salarioBase + calcularPagoHorasExtra();
}

// Bonificacion por guardias
double Medico::calcularBonificaciones() {
	return horasGuardia * pagoPorGuardia;
}

string Medico::getTipo() { return "Medico"; }

string Medico::serializar() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "MEDICO|" << Empleado::serializar() << "|" << especialidad << "|"
	  << numeroColegiado << "|" << horasGuardia << "|" << pagoPorGuardia;
	return s.str();
}

string Medico::obtenerResumen() {
	stringstream s;
	s << fixed << setprecision(2);
	s << Empleado::obtenerResumen()
	  << "Especialidad.....= " << especialidad << endl
	  << "No. colegiado....= " << numeroColegiado << endl
	  << "Horas de guardia.= " << horasGuardia << " x " << pagoPorGuardia << endl;
	return s.str();
}

string Medico::getEspecialidad() { return especialidad; }

void Medico::setHorasGuardia(int horas) { horasGuardia = horas; }
