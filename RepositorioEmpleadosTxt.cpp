#include "RepositorioEmpleadosTxt.h"
#include "FabricaEmpleado.h"

RepositorioEmpleadosTxt::RepositorioEmpleadosTxt(string ruta) {
	rutaArchivo = ruta;
}

void RepositorioEmpleadosTxt::guardarTodos(ListaEmpleados& lista) {
	ofstream archivo;
	archivo.open(rutaArchivo.c_str());
	for (int i = 0; i < lista.tamanio(); i++) {
		archivo << lista.obtener(i)->serializar() << endl;
	}
	archivo.close();
}

void RepositorioEmpleadosTxt::cargarTodos(ListaEmpleados& lista) {
	ifstream archivo;
	archivo.open(rutaArchivo.c_str());
	if (!archivo.is_open()) {
		return;   // primera ejecucion: el archivo aun no existe
	}
	string linea;
	while (getline(archivo, linea)) {
		if (!linea.empty() && linea[linea.length() - 1] == '\r') {
			linea.erase(linea.length() - 1);
		}
		if (linea.empty()) {
			continue;
		}
		Empleado* e = FabricaEmpleado::crearDesdeRegistro(linea);
		if (e != NULL) {
			lista.agregarAlFinal(e);
		}
	}
	archivo.close();
}
