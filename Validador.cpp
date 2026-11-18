#include "Validador.h"

// Solo digitos (se acepta el 0), maximo 9 para no desbordar un int
bool Validador::esEnteroPositivo(string texto) {
	if (texto.empty() || texto.length() > 9) {
		return false;
	}
	for (unsigned int i = 0; i < texto.length(); i++) {
		if (texto[i] < '0' || texto[i] > '9') {
			return false;
		}
	}
	return true;
}

// Digitos con un unico punto decimal opcional (se acepta el 0)
bool Validador::esDecimalPositivo(string texto) {
	if (texto.empty() || texto.length() > 12) {
		return false;
	}
	int puntos = 0;
	int digitos = 0;
	for (unsigned int i = 0; i < texto.length(); i++) {
		if (texto[i] == '.') {
			puntos++;
		} else if (texto[i] >= '0' && texto[i] <= '9') {
			digitos++;
		} else {
			return false;
		}
	}
	return (puntos <= 1 && digitos > 0);
}

// No vacio y sin el caracter '|' (separador de los archivos de texto)
bool Validador::esTextoNoVacio(string texto) {
	bool hayContenido = false;
	for (unsigned int i = 0; i < texto.length(); i++) {
		if (texto[i] == '|') {
			return false;
		}
		if (texto[i] != ' ' && texto[i] != '\t') {
			hayContenido = true;
		}
	}
	return hayContenido;
}

// Entre 9 y 12 digitos (cedula nacional o documento de residente)
bool Validador::esCedulaValida(string cedula) {
	if (cedula.length() < 9 || cedula.length() > 12) {
		return false;
	}
	for (unsigned int i = 0; i < cedula.length(); i++) {
		if (cedula[i] < '0' || cedula[i] > '9') {
			return false;
		}
	}
	return true;
}

// Formato dd/mm/aaaa con fecha real de calendario
bool Validador::esFechaValida(string fecha) {
	if (fecha.length() != 10 || fecha[2] != '/' || fecha[5] != '/') {
		return false;
	}
	for (int i = 0; i < 10; i++) {
		if (i != 2 && i != 5 && (fecha[i] < '0' || fecha[i] > '9')) {
			return false;
		}
	}
	int dia = (fecha[0] - '0') * 10 + (fecha[1] - '0');
	int mes = (fecha[3] - '0') * 10 + (fecha[4] - '0');
	int anio = (fecha[6] - '0') * 1000 + (fecha[7] - '0') * 100 + (fecha[8] - '0') * 10 + (fecha[9] - '0');
	if (anio < 1900 || anio > 2100 || mes < 1 || mes > 12 || dia < 1) {
		return false;
	}
	int diasMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	bool bisiesto = (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
	int maxDias = diasMes[mes - 1];
	if (mes == 2 && bisiesto) {
		maxDias = 29;
	}
	return dia <= maxDias;
}
