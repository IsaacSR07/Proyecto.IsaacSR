#include <iostream>
#include "RepositorioEmpleadosTxt.h"
#include "RepositorioDepartamentosTxt.h"
#include "RepositorioPlanillaTxt.h"
#include "ControladorEmpleados.h"
#include "ControladorDepartamentos.h"
#include "ControladorPlanilla.h"
#include "CalculadoraSalario.h"
#include "DeduccionPorcentual.h"
#include "MenuConsola.h"

using namespace std;

int main() {
	// Capa de persistencia (archivos de texto plano)
	RepositorioEmpleadosTxt repoEmpleados("empleados.txt");
	RepositorioDepartamentosTxt repoDepartamentos("departamentos.txt");
	RepositorioPlanillaTxt repoPlanilla("planilla.txt");
	
	// Deducciones de ley (la calculadora se hace duena de los objetos)
	CalculadoraSalario calculadora;
	calculadora.agregarDeduccion(new DeduccionPorcentual("CCSS - Seguro de Enfermedad y Maternidad", 5.50));
	calculadora.agregarDeduccion(new DeduccionPorcentual("CCSS - Invalidez, Vejez y Muerte", 4.17));
	calculadora.agregarDeduccion(new DeduccionPorcentual("Banco Popular", 1.00));
	
	// Controladores (logica de negocio), con inyeccion de dependencias
	ControladorEmpleados ctrlEmpleados(repoEmpleados);
	ControladorDepartamentos ctrlDepartamentos(repoDepartamentos);
	ControladorPlanilla ctrlPlanilla(repoPlanilla, ctrlEmpleados, ctrlDepartamentos, calculadora);
	
	// Carga automatica al iniciar (el orden importa: la planilla enlaza empleados y departamentos)
	ctrlEmpleados.cargar();
	ctrlDepartamentos.cargar();
	ctrlPlanilla.cargar();
	
	// Interfaz de usuario
	MenuConsola menu(ctrlEmpleados, ctrlDepartamentos, ctrlPlanilla);
	menu.ejecutar();
	return 0;
}
