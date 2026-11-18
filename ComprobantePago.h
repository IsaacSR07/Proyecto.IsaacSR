#ifndef COMPROBANTEPAGO_H
#define COMPROBANTEPAGO_H
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Empleado.h"
#include "Departamento.h"

using namespace std;

class ComprobantePago {
private:
	int idComprobante;
	Empleado* empleado;           // agregacion: no se libera aqui
	Departamento* departamento;   // agregacion: no se libera aqui
	string fecha;
	double salarioBruto;
	double bonificaciones;
	double totalDeducciones;
	double salarioNeto;
public:
	ComprobantePago(int, Empleado*, Departamento*, string, double, double, double);
	~ComprobantePago();
	int getIdComprobante();
	Empleado* getEmpleado();
	Departamento* getDepartamento();
	string getFecha();
	double getSalarioBruto();
	double getBonificaciones();
	double getTotalDeducciones();
	double getSalarioNeto();
	string obtenerResumen();
	string serializar();
};

#endif
