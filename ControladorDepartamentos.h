#ifndef CONTROLADORDEPARTAMENTOS_H
#define CONTROLADORDEPARTAMENTOS_H
#include <iostream>
#include "ListaDepartamentos.h"
#include "Departamento.h"
#include "IRepositorioDepartamentos.h"

using namespace std;

class ControladorDepartamentos {
private:
	ListaDepartamentos departamentos;
	IRepositorioDepartamentos& repositorio;
public:
	ControladorDepartamentos(IRepositorioDepartamentos&);
	~ControladorDepartamentos();
	void cargar();
	void guardar();
	bool registrar(Departamento*);
	Departamento* buscarPorId(int);
	bool eliminar(int);
	ListaDepartamentos& getDepartamentos();
};

#endif
