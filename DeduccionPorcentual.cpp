#include "DeduccionPorcentual.h"

DeduccionPorcentual::DeduccionPorcentual(string nom, double porc) {
	nombre = nom;
	porcentaje = porc;
}

string DeduccionPorcentual::getNombre() { return nombre; }

double DeduccionPorcentual::calcular(double salarioBruto) {
	return salarioBruto * porcentaje / 100.0;
}
