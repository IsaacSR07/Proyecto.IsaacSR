#include "Enfermero.h"

Enfermero::Enfermero(int i, string nom, string ape, string ced, string fecha, double sal, int idDep, int idPue,
					 string tur, string nivel)
	: Empleado(i, nom, ape, ced, fecha, sal, idDep, idPue) {
	turno = tur;
	nivelAcademico = nivel;
}

double Enfermero::calcularSalarioBruto() {
	return salarioBase + calcularPagoHorasExtra();
}

// Bonificacion del 20% del salario base por turno nocturno
double Enfermero::calcularBonificaciones() {
	if (turno == "Nocturno") {
		return salarioBase * 0.20;
	}
	return 0;
}

string Enfermero::getTipo() { return "Enfermero"; }

string Enfermero::serializar() {
	stringstream s;
	s << "ENFERMERO|" << Empleado::serializar() << "|" << turno << "|" << nivelAcademico;
	return s.str();
}

string Enfermero::obtenerResumen() {
	stringstream s;
	s << Empleado::obtenerResumen()
	  << "Turno............= " << turno << endl
	  << "Nivel academico..= " << nivelAcademico << endl;
	return s.str();
}

void Enfermero::setTurno(string tur) { turno = tur; }
