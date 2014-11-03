#include "Ciudad.h"
#include <stdlib.h>


Ciudad::Ciudad() {
    nombre = "";
    cantHabitantes = 0;
}

Ciudad::Ciudad(string nom, int cantHab) {
	nombre = nom;
	cantHabitantes = cantHab;
}

string Ciudad::nombreCiudad() {
    return nombre;
}

int Ciudad::cantidadHabitantes() {
    return cantHabitantes;
}

void Ciudad::nacenHabitantes(int cantNacidos) {
	cantHabitantes += cantNacidos;
}

void Ciudad::muerenHabitantes(int cantMuertos) {
	cantHabitantes -= cantMuertos;

	if( cantHabitantes < 0 )
		cantHabitantes = 0;
}

void Ciudad::leerCiudad(istream& in) {
	char conector;
	string cantHabsString;

	in >> conector; // lee el caracter "("
	getline(in,nombre,';');
	getline(in,cantHabsString,')');
	cantHabitantes = atoi(cantHabsString.c_str());
}

void Ciudad::imprimirCiudad(ostream& out) {
	out << "(" << nombre << ";" << cantHabitantes << ")";
}
