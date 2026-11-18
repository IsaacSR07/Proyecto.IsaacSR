#include "ComprobantePago.h"

ComprobantePago::ComprobantePago(int idComp, Empleado* emp, Departamento* dep, string fec,
								 double bruto, double bonif, double deducciones) {
	idComprobante = idComp;
	empleado = emp;
	departamento = dep;
	fecha = fec;
	salarioBruto = bruto;
	bonificaciones = bonif;
	totalDeducciones = deducciones;
	salarioNeto = bruto + bonif - deducciones;
}

// Los punteros a Empleado y Departamento NO se liberan: existen de forma independiente
ComprobantePago::~ComprobantePago() {}

int ComprobantePago::getIdComprobante() { return idComprobante; }
Empleado* ComprobantePago::getEmpleado() { return empleado; }
Departamento* ComprobantePago::getDepartamento() { return departamento; }
string ComprobantePago::getFecha() { return fecha; }
double ComprobantePago::getSalarioBruto() { return salarioBruto; }
double ComprobantePago::getBonificaciones() { return bonificaciones; }
double ComprobantePago::getTotalDeducciones() { return totalDeducciones; }
double ComprobantePago::getSalarioNeto() { return salarioNeto; }

string ComprobantePago::obtenerResumen() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "------------Comprobante de pago------------" << endl
	  << "No. comprobante..= " << idComprobante << endl
	  << "Fecha............= " << fecha << endl
	  << "Empleado.........= " << empleado->getNombre() << " " << empleado->getApellido()
	  << " (ID " << empleado->getId() << ")" << endl
	  << "Departamento.....= " << departamento->getNombre() << endl
	  << "Salario bruto....= " << salarioBruto << endl
	  << "Bonificaciones...= " << bonificaciones << endl
	  << "Deducciones......= " << totalDeducciones << endl
	  << "Salario neto.....= " << salarioNeto << endl;
	return s.str();
}

string ComprobantePago::serializar() {
	stringstream s;
	s << fixed << setprecision(2);
	s << idComprobante << "|" << empleado->getId() << "|" << departamento->getId() << "|"
	  << fecha << "|" << salarioBruto << "|" << bonificaciones << "|"
	  << totalDeducciones << "|" << salarioNeto;
	return s.str();
}
