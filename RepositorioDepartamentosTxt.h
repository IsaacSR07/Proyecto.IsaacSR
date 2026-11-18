#ifndef REPOSITORIODEPARTAMENTOSTXT_H
#define REPOSITORIODEPARTAMENTOSTXT_H
#include <iostream>
#include <fstream>
#include "IRepositorioDepartamentos.h"

using namespace std;

class RepositorioDepartamentosTxt : public IRepositorioDepartamentos {
private:
	string rutaArchivo;
public:
	RepositorioDepartamentosTxt(string);
	void guardarTodos(ListaDepartamentos&) override;
	void cargarTodos(ListaDepartamentos&) override;
};

#endif
