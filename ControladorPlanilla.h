#ifndef CONTROLADORPLANILLA_H
#define CONTROLADORPLANILLA_H
#include <iostream>
#include "ListaComprobantes.h"
#include "ComprobantePago.h"
#include "IRepositorioPlanilla.h"
#include "ControladorEmpleados.h"
#include "ControladorDepartamentos.h"
#include "CalculadoraSalario.h"

using namespace std;

class ControladorPlanilla {
private:
	ListaComprobantes comprobantes;
	IRepositorioPlanilla& repositorio;
	ControladorEmpleados& ctrlEmpleados;
	ControladorDepartamentos& ctrlDepartamentos;
	CalculadoraSalario& calculadora;
public:
	ControladorPlanilla(IRepositorioPlanilla&, ControladorEmpleados&, ControladorDepartamentos&, CalculadoraSalario&);
	~ControladorPlanilla();
	void cargar();
	void guardar();
	ComprobantePago* procesarPago(int, string);
	int procesarPlanillaCompleta(string);
	ListaComprobantes& getComprobantes();
};

#endif
