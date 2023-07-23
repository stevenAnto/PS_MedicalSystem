#include <iostream>
#include "crudPacientesInterface.h"
using namespace std;


int main() {
	vector <Paciente> pacientes;
	pacientes=Leer();
	imprimirVector(pacientes);
	//CrearConsola();//Para pruebas en consola
	Crear(1,"Esteven","Calcina",15925);
	Crear(2,"Antony","Aco",15925);
	Crear(3,"Henry","Galvez",15925);
	Crear(4,"kev","El Goleador",15925);
	Crear(5,"Fantasma","Fantasmon",157749);
	cout<<"Se termino de ingresar"<<endl;
	pacientes=Leer();
	imprimirVector(pacientes);
	Actualizar(5,"Nuevo","Talento",159357);
	pacientes=Leer();
	imprimirVector(pacientes);
	Borrar(2);
	pacientes=Leer();
	imprimirVector(pacientes);
	return 0;
}
