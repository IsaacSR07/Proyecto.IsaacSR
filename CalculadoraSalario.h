#ifndef CALCULADORASALARIO_H
#define CALCULADORASALARIO_H
#include <iostream>
#include "ListaDeducciones.h"
#include "IDeduccion.h"
#include "Empleado.h"

using namespace std;

class CalculadoraSalario {
private:
	ListaDeducciones deducciones;
public:
	CalculadoraSalario();
	~CalculadoraSalario();
	void agregarDeduccion(IDeduccion*);
	double calcularDeducciones(double);
	double calcularSalarioNeto(Empleado&);
};

#endif
