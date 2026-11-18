#include "RepositorioPlanillaTxt.h"
#include "ControladorEmpleados.h"
#include "ControladorDepartamentos.h"
#include <cstdlib>

RepositorioPlanillaTxt::RepositorioPlanillaTxt(string ruta) {
	rutaArchivo = ruta;
}

void RepositorioPlanillaTxt::guardarTodos(ListaComprobantes& lista) {
	ofstream archivo;
	archivo.open(rutaArchivo.c_str());
	for (int i = 0; i < lista.tamanio(); i++) {
		archivo << lista.obtener(i)->serializar() << endl;
	}
	archivo.close();
}

/*
 Formato: idComprobante|idEmpleado|idDepartamento|fecha|bruto|bonificaciones|deducciones|neto
 El empleado y el departamento se enlazan buscandolos en los controladores.
*/
void RepositorioPlanillaTxt::cargarTodos(ListaComprobantes& lista, ControladorEmpleados& ce, ControladorDepartamentos& cd) {
	ifstream archivo;
	archivo.open(rutaArchivo.c_str());
	if (!archivo.is_open()) {
		return;
	}
	string linea;
	while (getline(archivo, linea)) {
		if (!linea.empty() && linea[linea.length() - 1] == '\r') {
			linea.erase(linea.length() - 1);
		}
		if (linea.empty()) {
			continue;
		}
		string campos[8];
		int n = 0;
		string campo;
		stringstream ss(linea);
		while (n < 8 && getline(ss, campo, '|')) {
			campos[n] = campo;
			n++;
		}
		if (n < 7) {
			continue;
		}
		Empleado* emp = ce.buscarPorId(atoi(campos[1].c_str()));
		Departamento* dep = cd.buscarPorId(atoi(campos[2].c_str()));
		if (emp == NULL || dep == NULL) {
			continue;
		}
		lista.agregarAlFinal(new ComprobantePago(atoi(campos[0].c_str()), emp, dep, campos[3],
												 atof(campos[4].c_str()), atof(campos[5].c_str()),
												 atof(campos[6].c_str())));
	}
	archivo.close();
}
