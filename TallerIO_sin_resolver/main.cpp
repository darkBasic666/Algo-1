#include "Ciudad.cpp"
#include "Mapa.cpp"

#include <iostream>
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include <fstream>
#include <iomanip>

using namespace std;
int main () {
	Mapa soyElMapa;
	//Ejemplo simple para testear mientras programan imprimirCiudad e imprimirMapa
	/*Ciudad city1("BuenosAires",400000);
	Ciudad city2("Rosario",1234567);
	Ciudad city3("MiCiudad",1);
	
	//Mapa soyElMapa;
	soyElMapa.agregarRuta(city1,city2);
	soyElMapa.agregarRuta(city1,city3);
	//soyElMapa.agregarRuta(city2,city3);
	ofstream mapaO("mapa.txt");
	soyElMapa.imprimirMapa(mapaO);
	/*ifstream mapaI("mapa.txt");
	Mapa nuevoMapa;
	nuevoMapa.leerMapa(mapaI);
	nuevoMapa.imprimirMapa(cout);*/
	// MENU: TIENE UN UNICO MAPA (EL MAPA ACTUAL) SOBRE EL QUE SE PUEDE TRABAJAR Y SOBREESCRIBIRLO
	// COMPLETAR
	
	char op = ' ';
	while( op != 's' && op != 'S'){
		cout << "MENU :" << endl << endl;
		cout << "1- Leer Mapa"<< endl;
		cout << "2- Cargar Mapa"<< endl;
		cout << "3- Imprimir En Pantalla"<< endl;
		cout << "4- Agregar Ruta"<< endl;
		cout << "S- Salir"<< endl;
		cin >> op;
		system("clear");
		switch ( op ) {
		  case '1' :{ 
		  	Mapa nuevoMapa;
		  	string path;
		  	cout << "Path : ";
		  	cin >> path;
		  	ifstream mapaI(const_cast<char*>(path.c_str()));
		  	nuevoMapa.leerMapa(mapaI);
		  	soyElMapa = nuevoMapa;
		    break;
		  }case '2' :{ 
		  	string path;
		  	cout << "Path : ";
		  	cin >> path;
		  	ofstream mapaO(const_cast<char*>(path.c_str()));
			soyElMapa.imprimirMapa(mapaO);
		    break;
		  }case '3' :{  
		  	soyElMapa.imprimirMapa(cout);
		  	cout << endl;
		    break;
		  }case '4' :{
		  	soyElMapa.imprimirMapa(cout);
		  	cout << endl;
		  	string c1,c2; 
		  	cout << "Desde : " ;
		  	cin >> c1;
		  	cout << "Hasta : " ;
		  	cin >> c2;
		  	//cout << c1 << " " << c2;
		  	//soyElMapa.seLlama(c1).imprimirCiudad(cout);
		  	soyElMapa.agregarRuta(soyElMapa.seLlama(c1),soyElMapa.seLlama(c2));
		  	break;
		  } 
		}
	}
	return 0;
}
