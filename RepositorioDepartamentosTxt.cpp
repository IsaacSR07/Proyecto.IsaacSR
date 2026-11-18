#include "RepositorioDepartamentosTxt.h"
#include <cstdlib>

RepositorioDepartamentosTxt::RepositorioDepartamentosTxt(string ruta) {
	rutaArchivo = ruta;
}

void RepositorioDepartamentosTxt::guardarTodos(ListaDepartamentos& lista) {
	ofstream archivo;
	archivo.open(rutaArchivo.c_str());
	for (int i = 0; i < lista.tamanio(); i++) {
		archivo << lista.obtener(i)->serializar() << endl;
	}
	archivo.close();
}

/*
 Formato: "D|id|nombre|idJefe" abre un departamento y las lineas
 "P|id|nombre|descripcion" que le siguen son sus puestos.
*/
void RepositorioDepartamentosTxt::cargarTodos(ListaDepartamentos& lista) {
	ifstream archivo;
	archivo.open(rutaArchivo.c_str());
	if (!archivo.is_open()) {
		return;
	}
	string linea;
	Departamento* actual = NULL;
	while (getline(archivo, linea)) {
		if (!linea.empty() && linea[linea.length() - 1] == '\r') {
			linea.erase(linea.length() - 1);
		}
		if (linea.empty()) {
			continue;
		}
		string campos[4];
		int n = 0;
		string campo;
		stringstream ss(linea);
		while (n < 4 && getline(ss, campo, '|')) {
			campos[n] = campo;
			n++;
		}
		if (n < 4) {
			continue;
		}
		if (campos[0] == "D") {
			actual = new Departamento(atoi(campos[1].c_str()), campos[2], atoi(campos[3].c_str()));
			lista.agregarAlFinal(actual);
		} else if (campos[0] == "P" && actual != NULL) {
			actual->agregarPuesto(atoi(campos[1].c_str()), campos[2], campos[3]);
		}
	}
	archivo.close();
}
