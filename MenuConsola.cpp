#include "MenuConsola.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include "Validador.h"
#include <cstdlib>

MenuConsola::MenuConsola(ControladorEmpleados& ce, ControladorDepartamentos& cd, ControladorPlanilla& cp)
	: ctrlEmpleados(ce), ctrlDepartamentos(cd), ctrlPlanilla(cp) {}

void MenuConsola::ejecutar() {
	int opcion;
	do {
		cout << endl << "=====================================" << endl;
		cout << "   SISTEMA DE PLANILLA HOSPITALARIA" << endl;
		cout << "=====================================" << endl;
		cout << "[1] Gestion de empleados" << endl;
		cout << "[2] Gestion de departamentos" << endl;
		cout << "[3] Planilla y pagos" << endl;
		cout << "[0] Salir" << endl;
		opcion = leerEntero("Opcion: ");
		switch (opcion) {
		case 1: menuEmpleados(); break;
		case 2: menuDepartamentos(); break;
		case 3: menuPlanilla(); break;
		case 0: mostrarMensaje("Datos guardados. Hasta luego."); break;
		default: mostrarMensaje("Opcion no valida.");
		}
	} while (opcion != 0);
}

// ---------------------------------------------------------------
void MenuConsola::menuEmpleados() {
	int opcion;
	do {
		cout << endl << "---------- EMPLEADOS ----------" << endl;
		cout << "[1] Registrar empleado" << endl;
		cout << "[2] Listar empleados" << endl;
		cout << "[3] Buscar empleado por ID" << endl;
		cout << "[4] Actualizar salario base" << endl;
		cout << "[5] Registrar horas extra" << endl;
		cout << "[6] Actualizar horas de guardia (medico)" << endl;
		cout << "[7] Actualizar turno (enfermero)" << endl;
		cout << "[8] Reasignar departamento y puesto" << endl;
		cout << "[9] Eliminar empleado" << endl;
		cout << "[0] Volver" << endl;
		opcion = leerEntero("Opcion: ");
		switch (opcion) {
		case 1: {
			if (ctrlDepartamentos.getDepartamentos().estaVacia()) {
				mostrarMensaje("Primero debe registrar un departamento con puestos.");
				break;
			}
			int tipo = leerEntero("Tipo (1=Medico, 2=Enfermero, 3=Administrativo): ");
			if (tipo < 1 || tipo > 3) {
				mostrarMensaje("Tipo no valido.");
				break;
			}
			int id = leerEntero("ID del empleado: ");
			if (id <= 0 || ctrlEmpleados.buscarPorId(id) != NULL) {
				mostrarMensaje("ID invalido o ya registrado.");
				break;
			}
			string nombre = leerTexto("Nombre: ");
			string apellido = leerTexto("Apellido: ");
			string cedula;
			do {
				cedula = leerTexto("Cedula (solo digitos): ");
				if (!Validador::esCedulaValida(cedula)) {
					mostrarMensaje("Cedula no valida (9 a 12 digitos).");
				}
			} while (!Validador::esCedulaValida(cedula));
			string fecha;
			do {
				fecha = leerTexto("Fecha de ingreso (dd/mm/aaaa): ");
				if (!Validador::esFechaValida(fecha)) {
					mostrarMensaje("Fecha no valida.");
				}
			} while (!Validador::esFechaValida(fecha));
			double salario = leerDecimal("Salario base: ");
			while (salario <= 0) {
				mostrarMensaje("El salario debe ser mayor que cero.");
				salario = leerDecimal("Salario base: ");
			}
			int idDep = leerEntero("ID del departamento: ");
			Departamento* dep = ctrlDepartamentos.buscarPorId(idDep);
			if (dep == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			int idPue = leerEntero("ID del puesto: ");
			if (dep->buscarPuesto(idPue) == NULL) {
				mostrarMensaje("El puesto no existe en ese departamento.");
				break;
			}
			Empleado* nuevo = NULL;
			if (tipo == 1) {
				string esp = leerTexto("Especialidad: ");
				string colegiado = leerTexto("Numero de colegiado: ");
				int horasG = leerEntero("Horas de guardia: ");
				double pagoG = leerDecimal("Pago por hora de guardia: ");
				nuevo = new Medico(id, nombre, apellido, cedula, fecha, salario, idDep, idPue,
								   esp, colegiado, horasG, pagoG);
			} else if (tipo == 2) {
				int t;
				do {
					t = leerEntero("Turno (1=Diurno, 2=Nocturno): ");
				} while (t < 1 || t > 2);
				string nivel = leerTexto("Nivel academico: ");
				nuevo = new Enfermero(id, nombre, apellido, cedula, fecha, salario, idDep, idPue,
									  (t == 2) ? "Nocturno" : "Diurno", nivel);
			} else {
				string cargo = leerTexto("Cargo: ");
				double bonif = leerDecimal("Bonificacion: ");
				nuevo = new Administrativo(id, nombre, apellido, cedula, fecha, salario, idDep, idPue,
										   cargo, bonif);
			}
			if (ctrlEmpleados.registrar(nuevo)) {
				mostrarMensaje("Empleado registrado y guardado.");
			} else {
				delete nuevo;
				mostrarMensaje("No se pudo registrar el empleado.");
			}
			break;
		}
		case 2: {
			ListaEmpleados& lista = ctrlEmpleados.getEmpleados();
			if (lista.estaVacia()) {
				mostrarMensaje("No hay empleados registrados.");
			}
			for (int i = 0; i < lista.tamanio(); i++) {
				cout << endl << lista.obtener(i)->obtenerResumen();
			}
			break;
		}
		case 3: {
			Empleado* e = ctrlEmpleados.buscarPorId(leerEntero("ID del empleado: "));
			if (e == NULL) {
				mostrarMensaje("Empleado no encontrado.");
			} else {
				cout << endl << e->obtenerResumen();
			}
			break;
		}
		case 4: {
			int id = leerEntero("ID del empleado: ");
			double nuevo = leerDecimal("Nuevo salario base: ");
			if (nuevo <= 0) {
				mostrarMensaje("El salario debe ser mayor que cero.");
			} else if (ctrlEmpleados.actualizarSalario(id, nuevo)) {
				mostrarMensaje("Salario actualizado y guardado.");
			} else {
				mostrarMensaje("Empleado no encontrado.");
			}
			break;
		}
		case 5: {
			Empleado* e = ctrlEmpleados.buscarPorId(leerEntero("ID del empleado: "));
			if (e == NULL) {
				mostrarMensaje("Empleado no encontrado.");
				break;
			}
			int horas = leerEntero("Horas extra del periodo: ");
			double valor = leerDecimal("Valor por hora extra: ");
			e->setHorasExtra(horas, valor);
			ctrlEmpleados.guardar();
			mostrarMensaje("Horas extra registradas y guardadas.");
			break;
		}
		case 6: {
			Empleado* e = ctrlEmpleados.buscarPorId(leerEntero("ID del empleado: "));
			Medico* m = dynamic_cast<Medico*>(e);
			if (m == NULL) {
				mostrarMensaje("No existe un medico con ese ID.");
				break;
			}
			m->setHorasGuardia(leerEntero("Nuevas horas de guardia: "));
			ctrlEmpleados.guardar();
			mostrarMensaje("Horas de guardia actualizadas y guardadas.");
			break;
		}
		case 7: {
			Empleado* e = ctrlEmpleados.buscarPorId(leerEntero("ID del empleado: "));
			Enfermero* en = dynamic_cast<Enfermero*>(e);
			if (en == NULL) {
				mostrarMensaje("No existe un enfermero con ese ID.");
				break;
			}
			int t;
			do {
				t = leerEntero("Nuevo turno (1=Diurno, 2=Nocturno): ");
			} while (t < 1 || t > 2);
			en->setTurno((t == 2) ? "Nocturno" : "Diurno");
			ctrlEmpleados.guardar();
			mostrarMensaje("Turno actualizado y guardado.");
			break;
		}
		case 8: {
			Empleado* e = ctrlEmpleados.buscarPorId(leerEntero("ID del empleado: "));
			if (e == NULL) {
				mostrarMensaje("Empleado no encontrado.");
				break;
			}
			Departamento* dep = ctrlDepartamentos.buscarPorId(leerEntero("ID del nuevo departamento: "));
			if (dep == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			int idPue = leerEntero("ID del nuevo puesto: ");
			if (dep->buscarPuesto(idPue) == NULL) {
				mostrarMensaje("El puesto no existe en ese departamento.");
				break;
			}
			e->setIdDepartamento(dep->getId());
			e->setIdPuesto(idPue);
			ctrlEmpleados.guardar();
			mostrarMensaje("Asignacion actualizada y guardada.");
			break;
		}
		case 9: {
			int id = leerEntero("ID del empleado a eliminar: ");
			if (ctrlEmpleados.buscarPorId(id) == NULL) {
				mostrarMensaje("Empleado no encontrado.");
				break;
			}
			bool enUso = false;
			ListaComprobantes& comp = ctrlPlanilla.getComprobantes();
			for (int i = 0; i < comp.tamanio(); i++) {
				if (comp.obtener(i)->getEmpleado()->getId() == id) {
					enUso = true;
				}
			}
			ListaDepartamentos& deps = ctrlDepartamentos.getDepartamentos();
			for (int i = 0; i < deps.tamanio(); i++) {
				if (deps.obtener(i)->getIdJefe() == id) {
					enUso = true;
				}
			}
			if (enUso) {
				mostrarMensaje("No se puede eliminar: tiene comprobantes de pago o es jefe de un departamento.");
			} else {
				ctrlEmpleados.eliminar(id);
				mostrarMensaje("Empleado eliminado y cambios guardados.");
			}
			break;
		}
		case 0: break;
		default: mostrarMensaje("Opcion no valida.");
		}
	} while (opcion != 0);
}

// ---------------------------------------------------------------
void MenuConsola::menuDepartamentos() {
	int opcion;
	do {
		cout << endl << "---------- DEPARTAMENTOS ----------" << endl;
		cout << "[1] Registrar departamento" << endl;
		cout << "[2] Listar departamentos y puestos" << endl;
		cout << "[3] Agregar puesto a un departamento" << endl;
		cout << "[4] Eliminar puesto de un departamento" << endl;
		cout << "[5] Cambiar jefe de departamento" << endl;
		cout << "[6] Eliminar departamento" << endl;
		cout << "[0] Volver" << endl;
		opcion = leerEntero("Opcion: ");
		switch (opcion) {
		case 1: {
			int id = leerEntero("ID del departamento: ");
			if (id <= 0 || ctrlDepartamentos.buscarPorId(id) != NULL) {
				mostrarMensaje("ID invalido o ya registrado.");
				break;
			}
			string nombre = leerTexto("Nombre del departamento: ");
			int jefe = leerEntero("ID del jefe (0 si aun no tiene): ");
			if (jefe != 0 && ctrlEmpleados.buscarPorId(jefe) == NULL) {
				mostrarMensaje("El empleado jefe no existe.");
				break;
			}
			Departamento* nuevo = new Departamento(id, nombre, jefe);
			if (ctrlDepartamentos.registrar(nuevo)) {
				mostrarMensaje("Departamento registrado y guardado.");
			} else {
				delete nuevo;
				mostrarMensaje("No se pudo registrar el departamento.");
			}
			break;
		}
		case 2: {
			ListaDepartamentos& lista = ctrlDepartamentos.getDepartamentos();
			if (lista.estaVacia()) {
				mostrarMensaje("No hay departamentos registrados.");
			}
			for (int i = 0; i < lista.tamanio(); i++) {
				Departamento* d = lista.obtener(i);
				cout << endl << "Departamento " << d->getId() << ": " << d->getNombre()
					 << " (ID jefe: " << d->getIdJefe() << ")" << endl;
				ListaPuestos& puestos = d->getPuestos();
				if (puestos.estaVacia()) {
					cout << "   (sin puestos)" << endl;
				}
				for (int j = 0; j < puestos.tamanio(); j++) {
					cout << "   Puesto " << puestos.obtener(j)->getId() << ": "
						 << puestos.obtener(j)->getNombre() << " - "
						 << puestos.obtener(j)->getDescripcion() << endl;
				}
			}
			break;
		}
		case 3: {
			Departamento* d = ctrlDepartamentos.buscarPorId(leerEntero("ID del departamento: "));
			if (d == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			int idPue = leerEntero("ID del nuevo puesto: ");
			if (idPue <= 0 || d->buscarPuesto(idPue) != NULL) {
				mostrarMensaje("ID de puesto invalido o ya existe en el departamento.");
				break;
			}
			string nombre = leerTexto("Nombre del puesto: ");
			string desc = leerTexto("Descripcion: ");
			d->agregarPuesto(idPue, nombre, desc);
			ctrlDepartamentos.guardar();
			mostrarMensaje("Puesto agregado y guardado.");
			break;
		}
		case 4: {
			Departamento* d = ctrlDepartamentos.buscarPorId(leerEntero("ID del departamento: "));
			if (d == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			int idPue = leerEntero("ID del puesto a eliminar: ");
			if (d->buscarPuesto(idPue) == NULL) {
				mostrarMensaje("El puesto no existe en ese departamento.");
				break;
			}
			bool enUso = false;
			ListaEmpleados& emps = ctrlEmpleados.getEmpleados();
			for (int i = 0; i < emps.tamanio(); i++) {
				if (emps.obtener(i)->getIdDepartamento() == d->getId() && emps.obtener(i)->getIdPuesto() == idPue) {
					enUso = true;
				}
			}
			if (enUso) {
				mostrarMensaje("No se puede eliminar: hay empleados asignados a ese puesto.");
			} else {
				d->eliminarPuesto(idPue);
				ctrlDepartamentos.guardar();
				mostrarMensaje("Puesto eliminado y cambios guardados.");
			}
			break;
		}
		case 5: {
			Departamento* d = ctrlDepartamentos.buscarPorId(leerEntero("ID del departamento: "));
			if (d == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			int jefe = leerEntero("ID del nuevo jefe (0 para ninguno): ");
			if (jefe != 0 && ctrlEmpleados.buscarPorId(jefe) == NULL) {
				mostrarMensaje("El empleado jefe no existe.");
				break;
			}
			d->setIdJefe(jefe);
			ctrlDepartamentos.guardar();
			mostrarMensaje("Jefe actualizado y guardado.");
			break;
		}
		case 6: {
			int id = leerEntero("ID del departamento a eliminar: ");
			if (ctrlDepartamentos.buscarPorId(id) == NULL) {
				mostrarMensaje("El departamento no existe.");
				break;
			}
			bool enUso = false;
			ListaEmpleados& emps = ctrlEmpleados.getEmpleados();
			for (int i = 0; i < emps.tamanio(); i++) {
				if (emps.obtener(i)->getIdDepartamento() == id) {
					enUso = true;
				}
			}
			ListaComprobantes& comp = ctrlPlanilla.getComprobantes();
			for (int i = 0; i < comp.tamanio(); i++) {
				if (comp.obtener(i)->getDepartamento()->getId() == id) {
					enUso = true;
				}
			}
			if (enUso) {
				mostrarMensaje("No se puede eliminar: tiene empleados o comprobantes asociados.");
			} else {
				ctrlDepartamentos.eliminar(id);
				mostrarMensaje("Departamento eliminado y cambios guardados.");
			}
			break;
		}
		case 0: break;
		default: mostrarMensaje("Opcion no valida.");
		}
	} while (opcion != 0);
}

// ---------------------------------------------------------------
void MenuConsola::menuPlanilla() {
	int opcion;
	do {
		cout << endl << "---------- PLANILLA Y PAGOS ----------" << endl;
		cout << "[1] Procesar pago de un empleado" << endl;
		cout << "[2] Procesar planilla completa" << endl;
		cout << "[3] Listar comprobantes de pago" << endl;
		cout << "[0] Volver" << endl;
		opcion = leerEntero("Opcion: ");
		switch (opcion) {
		case 1: {
			int id = leerEntero("ID del empleado: ");
			string fecha;
			do {
				fecha = leerTexto("Fecha del pago (dd/mm/aaaa): ");
				if (!Validador::esFechaValida(fecha)) {
					mostrarMensaje("Fecha no valida.");
				}
			} while (!Validador::esFechaValida(fecha));
			ComprobantePago* c = ctrlPlanilla.procesarPago(id, fecha);
			if (c == NULL) {
				mostrarMensaje("No se pudo procesar: empleado o departamento inexistente, o pago ya registrado en esa fecha.");
			} else {
				cout << endl << c->obtenerResumen();
				mostrarMensaje("Pago procesado y guardado.");
			}
			break;
		}
		case 2: {
			string fecha;
			do {
				fecha = leerTexto("Fecha de la planilla (dd/mm/aaaa): ");
				if (!Validador::esFechaValida(fecha)) {
					mostrarMensaje("Fecha no valida.");
				}
			} while (!Validador::esFechaValida(fecha));
			int cantidad = ctrlPlanilla.procesarPlanillaCompleta(fecha);
			cout << "Comprobantes generados: " << cantidad << endl;
			break;
		}
		case 3: {
			ListaComprobantes& lista = ctrlPlanilla.getComprobantes();
			if (lista.estaVacia()) {
				mostrarMensaje("No hay comprobantes registrados.");
			}
			for (int i = 0; i < lista.tamanio(); i++) {
				cout << endl << lista.obtener(i)->obtenerResumen();
			}
			break;
		}
		case 0: break;
		default: mostrarMensaje("Opcion no valida.");
		}
	} while (opcion != 0);
}

// ---------------------------------------------------------------
// Lectura validada: se repite hasta que la entrada sea correcta.
int MenuConsola::leerEntero(string mensaje) {
	string texto;
	while (true) {
		cout << mensaje;
		if (!getline(cin, texto)) {
			cout << endl;
			exit(0);   // fin de la entrada: los datos ya estan guardados
		}
		if (Validador::esEnteroPositivo(texto)) {
			return atoi(texto.c_str());
		}
		mostrarMensaje("Entrada no valida: digite un numero entero (0 o mayor).");
	}
}

double MenuConsola::leerDecimal(string mensaje) {
	string texto;
	while (true) {
		cout << mensaje;
		if (!getline(cin, texto)) {
			cout << endl;
			exit(0);
		}
		for (unsigned int i = 0; i < texto.length(); i++) {
			if (texto[i] == ',') {
				texto[i] = '.';
			}
		}
		if (Validador::esDecimalPositivo(texto)) {
			return atof(texto.c_str());
		}
		mostrarMensaje("Entrada no valida: digite un numero decimal (0 o mayor).");
	}
}

string MenuConsola::leerTexto(string mensaje) {
	string texto;
	while (true) {
		cout << mensaje;
		if (!getline(cin, texto)) {
			cout << endl;
			exit(0);
		}
		if (Validador::esTextoNoVacio(texto)) {
			size_t ini = texto.find_first_not_of(" \t");
			size_t fin = texto.find_last_not_of(" \t");
			return texto.substr(ini, fin - ini + 1);
		}
		mostrarMensaje("Entrada no valida: no puede estar vacia ni contener el caracter '|'.");
	}
}

void MenuConsola::mostrarMensaje(string mensaje) {
	cout << mensaje << endl;
}
