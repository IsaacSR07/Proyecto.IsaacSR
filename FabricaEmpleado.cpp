#include "FabricaEmpleado.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include <cstdlib>

/*
 Construye el empleado correcto a partir de una linea del archivo:
 TIPO|id|nombre|apellido|cedula|fecha|salarioBase|idDep|idPuesto|horasExtra|valorHoraExtra|campos propios...
 Devuelve NULL si la linea esta incompleta o el tipo no se conoce.
*/
Empleado* FabricaEmpleado::crearDesdeRegistro(string linea) {
	string campos[16];
	int n = 0;
	string campo;
	stringstream ss(linea);
	while (n < 16 && getline(ss, campo, '|')) {
		campos[n] = campo;
		n++;
	}
	if (n < 13) {
		return NULL;
	}
	int id = atoi(campos[1].c_str());
	double salario = atof(campos[6].c_str());
	int idDep = atoi(campos[7].c_str());
	int idPue = atoi(campos[8].c_str());
	int horasExtra = atoi(campos[9].c_str());
	double valorHoraExtra = atof(campos[10].c_str());
	Empleado* e = NULL;

	if (campos[0] == "MEDICO" && n == 15) {
		e = new Medico(id, campos[2], campos[3], campos[4], campos[5], salario, idDep, idPue,
					   campos[11], campos[12], atoi(campos[13].c_str()), atof(campos[14].c_str()));
	} else if (campos[0] == "ENFERMERO" && n == 13) {
		e = new Enfermero(id, campos[2], campos[3], campos[4], campos[5], salario, idDep, idPue,
						  campos[11], campos[12]);
	} else if (campos[0] == "ADMINISTRATIVO" && n == 13) {
		e = new Administrativo(id, campos[2], campos[3], campos[4], campos[5], salario, idDep, idPue,
							   campos[11], atof(campos[12].c_str()));
	}
	if (e != NULL) {
		e->setHorasExtra(horasExtra, valorHoraExtra);
	}
	return e;
}
