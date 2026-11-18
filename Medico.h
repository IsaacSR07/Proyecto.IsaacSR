#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"

class Medico : public Empleado {
private:
	string especialidad;
	string numeroColegiado;
	int horasGuardia;
	double pagoPorGuardia;
public:
	Medico(int, string, string, string, string, double, int, int, string, string, int, double);
	double calcularSalarioBruto() override;
	double calcularBonificaciones() override;
	string getTipo() override;
	string serializar() override;
	string obtenerResumen() override;
	string getEspecialidad();
	void setHorasGuardia(int);
};

#endif
