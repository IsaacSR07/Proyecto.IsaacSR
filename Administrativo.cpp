#include "Administrativo.h"

Administrativo::Administrativo(int i, string nom, string ape, string ced, string fecha, double sal, int idDep, int idPue,
							   string car, double bonif)
	: Empleado(i, nom, ape, ced, fecha, sal, idDep, idPue) {
	cargo = car;
	bonificacion = bonif;
}

double Administrativo::calcularSalarioBruto() {
	return salarioBase + calcularPagoHorasExtra();
}

double Administrativo::calcularBonificaciones() {
	return bonificacion;
}

string Administrativo::getTipo() { return "Administrativo"; }

string Administrativo::serializar() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "ADMINISTRATIVO|" << Empleado::serializar() << "|" << cargo << "|" << bonificacion;
	return s.str();
}

string Administrativo::obtenerResumen() {
	stringstream s;
	s << fixed << setprecision(2);
	s << Empleado::obtenerResumen()
	  << "Cargo............= " << cargo << endl
	  << "Bonificacion.....= " << bonificacion << endl;
	return s.str();
}
