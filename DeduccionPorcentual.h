#ifndef DEDUCCIONPORCENTUAL_H
#define DEDUCCIONPORCENTUAL_H
#include "IDeduccion.h"

class DeduccionPorcentual : public IDeduccion {
private:
	string nombre;
	double porcentaje;
public:
	DeduccionPorcentual(string, double);
	string getNombre() override;
	double calcular(double) override;
};

#endif
