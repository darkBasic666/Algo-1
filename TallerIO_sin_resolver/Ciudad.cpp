#include "Ciudad.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>     
#include <stdlib.h> 


using namespace std;
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
	string str;
	getline(in,str,',');
	nombre = str;
	getline(in,str);
	cantHabitantes = atoi(str.c_str());
}

void Ciudad::imprimirCiudad(ostream& out) {
	out << "(" << nombre << "," << cantHabitantes << ")";
}