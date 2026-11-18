#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"

class Enfermero : public Empleado {
private:
	string turno;
	string nivelAcademico;
public:
	Enfermero(int, string, string, string, string, double, int, int, string, string);
	double calcularSalarioBruto() override;
	double calcularBonificaciones() override;
	string getTipo() override;
	string serializar() override;
	string obtenerResumen() override;
	void setTurno(string);
};

#endif
