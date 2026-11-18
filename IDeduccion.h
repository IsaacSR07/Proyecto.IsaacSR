#ifndef IDEDUCCION_H
#define IDEDUCCION_H
#include <iostream>

using namespace std;

class IDeduccion {
public:
	virtual ~IDeduccion() {}
	virtual string getNombre() = 0;
	virtual double calcular(double) = 0;
};

#endif
