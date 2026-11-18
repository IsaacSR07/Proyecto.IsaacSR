#ifndef PUESTO_H
#define PUESTO_H
#include <iostream>
#include <sstream>

using namespace std;

class Puesto {
private:
	int id;
	string nombre;
	string descripcion;
public:
	Puesto(int, string, string);
	~Puesto();
	int getId();
	string getNombre();
	string getDescripcion();
	string serializar();
};

#endif
