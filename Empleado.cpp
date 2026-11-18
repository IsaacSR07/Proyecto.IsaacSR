#include "Empleado.h"

Empleado::Empleado(int i, string nom, string ape, string ced, string fecha, double sal, int idDep, int idPue) {
	id = i;
	nombre = nom;
	apellido = ape;
	cedula = ced;
	fechaIngreso = fecha;
	salarioBase = sal;
	idDepartamento = idDep;
	idPuesto = idPue;
	horasExtra = 0;
	valorHoraExtra = 0;
}

Empleado::~Empleado() {}

double Empleado::calcularBonificaciones() {
	return 0;
}

double Empleado::calcularPagoHorasExtra() {
	return horasExtra * valorHoraExtra;
}

void Empleado::setHorasExtra(int horas, double valor) {
	horasExtra = horas;
	valorHoraExtra = valor;
}

void Empleado::setSalarioBase(double sal) { salarioBase = sal; }
void Empleado::setIdDepartamento(int idDep) { idDepartamento = idDep; }
void Empleado::setIdPuesto(int idPue) { idPuesto = idPue; }

int Empleado::getId() { return id; }
string Empleado::getNombre() { return nombre; }
string Empleado::getApellido() { return apellido; }
string Empleado::getCedula() { return cedula; }
string Empleado::getFechaIngreso() { return fechaIngreso; }
double Empleado::getSalarioBase() { return salarioBase; }
int Empleado::getIdDepartamento() { return idDepartamento; }
int Empleado::getIdPuesto() { return idPuesto; }

string Empleado::obtenerResumen() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "------------" << getTipo() << "------------" << endl
	  << "ID...............= " << id << endl
	  << "Nombre...........= " << nombre << " " << apellido << endl
	  << "Cedula...........= " << cedula << endl
	  << "Fecha de ingreso.= " << fechaIngreso << endl
	  << "Departamento.....= " << idDepartamento << endl
	  << "Puesto...........= " << idPuesto << endl
	  << "Salario base.....= " << salarioBase << endl
	  << "Horas extra......= " << horasExtra << " x " << valorHoraExtra << endl;
	return s.str();
}

/*
 Metodo virtual puro con implementacion: escribe los campos comunes
 (en el mismo orden que lee FabricaEmpleado). Las clases hijas lo
 invocan como Empleado::serializar() y agregan sus campos propios.
*/
string Empleado::serializar() {
	stringstream s;
	s << fixed << setprecision(2);
	s << id << "|" << nombre << "|" << apellido << "|" << cedula << "|"
	  << fechaIngreso << "|" << salarioBase << "|" << idDepartamento << "|"
	  << idPuesto << "|" << horasExtra << "|" << valorHoraExtra;
	return s.str();
}
