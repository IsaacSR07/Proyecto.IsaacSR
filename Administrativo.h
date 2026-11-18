#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

class Administrativo : public Empleado {
private:
	string cargo;
	double bonificacion;
public:
	Administrativo(int, string, string, string, string, double, int, int, string, double);
	double calcularSalarioBruto() override;
	double calcularBonificaciones() override;
	string getTipo() override;
	string serializar() override;
	string obtenerResumen() override;
};

#endif
