#ifndef MAPA_H
#define MAPA_H

#include "Ciudad.h"
#include <vector>

using std::vector;
using std::string;
using std::istream;
using std::ostream;
using std::endl;

class Mapa{
	public:
		Mapa();
		const vector<Ciudad>& listaCiudades();
		void agregarRuta(Ciudad u, Ciudad v);
		int cantidadDestinos(Ciudad u);
		bool sonVecinos(Ciudad u, Ciudad v);

		// METODOS A IMPLEMENTAR
		void leerMapa(istream& in);
		void imprimirMapa(ostream& out);
		Ciudad seLlama(string);
	private:
		vector<Ciudad> ciudades;
		vector<vector<Ciudad> > vecinos;
		
		// para cada ciudad, hay un vector que enumera todas
		// las Ciudades vecinas a ella
};

#endif
