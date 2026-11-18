#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

class Empleado {
protected:
	int id;
	string nombre;
	string apellido;
	string cedula;
	string fechaIngreso;
	double salarioBase;
	int idDepartamento;
	int idPuesto;
	int horasExtra;
	double valorHoraExtra;
public:
	Empleado(int, string, string, string, string, double, int, int);
	virtual ~Empleado();
	virtual double calcularSalarioBruto() = 0;
	virtual double calcularBonificaciones();
	virtual string getTipo() = 0;
	virtual string serializar() = 0;
	virtual string obtenerResumen();
	double calcularPagoHorasExtra();
	void setHorasExtra(int, double);
	void setSalarioBase(double);
	void setIdDepartamento(int);
	void setIdPuesto(int);
	int getId();
	string getNombre();
	string getApellido();
	string getCedula();
	string getFechaIngreso();
	double getSalarioBase();
	int getIdDepartamento();
	int getIdPuesto();
};

#endif
