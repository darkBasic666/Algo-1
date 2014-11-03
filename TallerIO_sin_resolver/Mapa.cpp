#include "Mapa.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>     
#include <stdlib.h> 
#include <sstream>

using namespace std;
Mapa::Mapa() {
	ciudades = vector<Ciudad>();
	vecinos = vector<vector<Ciudad> > (0,vector<Ciudad>(0));
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
            vecinos[i].push_back(u);
            existeU = true;
        }
        if( ciudades[i] == v ) {
            vecinos[i].push_back(u);
            vecinos[i].push_back(v);
            existeV = true;
        }
		i++;
	}


    if( !existeU ) {
        ciudades.push_back(u);
        vecinos.push_back(vector<Ciudad>());
        vecinos[ciudades.size()-1].push_back(v);
        vecinos[ciudades.size()-1].push_back(u);
    }

    if( !existeV ) {
        ciudades.push_back(v);
        vecinos.push_back(vector<Ciudad>());
        vecinos[ciudades.size()-1].push_back(u);
        vecinos[ciudades.size()-1].push_back(v);
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
    int cantC; 
    int cantV;
    string str;
    getline(in,str,' ');
    cantC = atoi(str.c_str());
    getline(in,str);
    cantV = atoi(str.c_str());
    istringstream iss;
    for (int i = 0; i < cantC; ++i){
        Ciudad c;
        ciudades.push_back(c);
        getline(in,str,')');
        iss.str(str.substr(2,str.size()-2));
        ciudades.at(i).leerCiudad(iss);
        iss.clear();
    }
    getline(in,str);
    for (int i = 0; i < cantV; ++i){
        vector<Ciudad> lc;
        getline(in,str,'}');
        iss.str(str.substr(2,str.size()-2));
        string antRest  , rest= str.substr(2,str.size()-2);
        do{ 
            antRest = rest;
            getline(iss,str,',');
            getline(iss,rest);
            iss.clear();
            iss.str(rest);
            Ciudad c = seLlama(str);
            lc.push_back(c);
            //cout << antRest << " → " << rest <<endl;
            //cout << antRest.find(',')<< " < " << antRest.size()<< endl;
        }while(antRest.find(',')< antRest.size());
        vecinos.push_back(lc);
        iss.clear();
    }
    
}

void Mapa::imprimirMapa(ostream& out) {
	out << ciudades.size() << " " << vecinos.size() << endl;
    out << "[";
    int i = 0;
    for (; i < ciudades.size() -1; ++i){
        ciudades.at(i).imprimirCiudad(out);out << ",";
    }
    ciudades.at(i).imprimirCiudad(out);
    out << "]" << endl << "[";
    i = 0;
    for (; i < vecinos.size() -1; ++i){
        out << "{" ;
        int j = 0;
        for (; j < vecinos.at(i).size()-1; ++j){
            out << vecinos.at(i).at(j).nombreCiudad() <<  ",";
        }
        out << vecinos.at(i).at(j).nombreCiudad() <<  "},";
    }
    
    out <<  "{" ;
    int j = 0;
    for (; j < vecinos.at(i).size()-1; ++j){
         out << vecinos.at(i).at(j).nombreCiudad() <<  ",";
    }
    out << vecinos.at(i).at(j).nombreCiudad() <<  "}";
    out << "]" << endl;
}


Ciudad Mapa::seLlama(string nombre){
    int i = 0;
    while(ciudades.at(i).nombreCiudad() != nombre){
        i++;
    }
    return ciudades.at(i);
}