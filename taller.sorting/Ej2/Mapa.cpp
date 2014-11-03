#include "Mapa.h"
#include <vector>

Mapa::Mapa() {
	ciudades = vector<Ciudad>();
	vecinos = vector<vector<Ciudad> > (0,vector<Ciudad>());
}

const vector<Ciudad>& Mapa::listaCiudades() {
	return ciudades;
}

void Mapa::agregarRuta(Ciudad u, Ciudad v) {
    // Si ya son vecinos, no hay nada que hacer
    if( sonVecinos(u,v) )
        return;

	// Si ya existe la ciudad, agrego la vecindad nueva
    bool existeU = false, existeV = false;
    int i = 0;
    while ( i < ciudades.size() ) {
        if( ciudades[i] == u ) {
            vecinos[i].push_back(v);
            existeU = true;
        }
        if( ciudades[i] == v ) {
            vecinos[i].push_back(u);
            existeV = true;
        }
		i++;
	}

	/* Si no existia la ciudad, la agrego al vector de ciudades,
	 * creo un vector de vecinos para la nueva ciudad, y
	 * agrego al nuevo vecino a este vector */
    if( !existeU ) {
        ciudades.push_back(u);
        vecinos.push_back(vector<Ciudad>());
        vecinos[ciudades.size()-1].push_back(v);
    }

    if( !existeV ) {
        ciudades.push_back(v);
        vecinos.push_back(vector<Ciudad>());
        vecinos[ciudades.size()-1].push_back(u);
    }
}

// Cantidad de vecinos de la ciudad u
int Mapa::cantidadDestinos(Ciudad u) {
    int result = 0;
    int i = 0;
    while( i < ciudades.size() ) {
        if( ciudades[i] == u ) {
            result = (int) vecinos[i].size();
            break;
        }
        i++;
	}
    return result;
}

// Devuelve si true si y solo si las dos ciudades son vecinas
bool Mapa::sonVecinos(Ciudad u, Ciudad v) {
    bool result = false;
   
    int i = 0, j = 0;
    while( i < ciudades.size() ) {
		if( ciudades[i] == u ) {
			while( j < vecinos[i].size() ) {
				if( vecinos[i][j] == v )
					result = true;
				j++;
			}
		}
		i++;
	}

    return result;
}

void Mapa::leerMapa(istream& in) {
	int cantCiudades, cantRutas;
	in >> cantCiudades >> cantRutas;

	// LECTURA DE CIUDADES
	char conector;
	in >> conector; // lee "[" y lo descarta
	
	int i = 0;
	while ( i < cantCiudades ) {
        Ciudad aux;
        aux.leerCiudad(in);
        ciudades.push_back(aux);
        vecinos.push_back(vector<Ciudad>());
        in >> conector; // lee "," o "]" y lo descarta
		i++;
	}

	// LECTURA DE VECINDADES
	in >> conector;
	i = 0;
	while ( i < cantRutas ) {
		string nom1, nom2;

		in >> conector; // lee "{" y lo descarta
		getline(in,nom1,',');
		getline(in,nom2,'}');
		in >> conector; // lee "," o "]" y lo descarta

		// Buscar ciudad con ese nombre y agregar ruta
		Ciudad ciudad1, ciudad2;
		int j = 0;
		while ( j < cantCiudades ) {
			if( ciudades[j].nombreCiudad() == nom1 )
				ciudad1 = ciudades[j];
			if( ciudades[j].nombreCiudad() == nom2 )
				ciudad2 = ciudades[j];
			j++;
		}
		agregarRuta(ciudad1,ciudad2);
		
		i++;
	}
}

void Mapa::imprimirMapa(ostream& out) {	

	ordenarMapa();

	// Cuento la cantidad total de rutas que hay en el mapa
    int cantRutas = 0;
    
    int i = 0, j = 0;
    while( i < ciudades.size() ) {
		cantRutas += vecinos[i].size();
		i++;
	}

    out << ciudades.size() << " " << cantRutas << endl;

	// Imprimo las ciudades con el formato indicado
    out << "[";
    i = 0;
    while ( i < ciudades.size() ) {
        if( i != 0 ) // salvo que sea la primera ciudad, imprimo una coma antes de la misma
			out << ",";
        ciudades[i].imprimirCiudad(out);
        i++;
	}
    out << "]" << endl;

	// Imprimo las vecindades con el formato indicado
	// ... (no hace falta en el taller de sorting)
}
void Mapa::ordenarMapa(){
	int i = 0;
	while(i < ciudades.size()){
		int j = i;
		while(  (j > 0) && ( (ciudades.at(j).cantidadHabitantes() < ciudades.at(j -1).cantidadHabitantes())
		 || ( (ciudades.at(j).cantidadHabitantes() == ciudades.at(j -1).cantidadHabitantes()) ) && 
		 (   ciudades.at(j).nombreCiudad() < ciudades.at(j -1).nombreCiudad()  ) )    ){
			Ciudad aux =  ciudades.at(j -1);
			ciudades.at(j-1) = ciudades.at(j);
			ciudades.at(j) = aux;
			j--;
		}
		i++;
	}
}