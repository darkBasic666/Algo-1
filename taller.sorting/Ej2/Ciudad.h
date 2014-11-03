#ifndef CIUDAD_H
#define CIUDAD_H

#include <iostream>
#include <string>

using std::string;
using std::istream;
using std::ostream;

class Ciudad{
	public:
		Ciudad(string nom, int cantHab);
		Ciudad();

		string nombreCiudad();
		int cantidadHabitantes();

		void nacenHabitantes(int cantNacidos);
		void muerenHabitantes(int cantMuertos);

        void leerCiudad(istream& in);
		void imprimirCiudad(ostream& out);

        bool operator == (Ciudad& city)
        {
            return ( nombre == city.nombreCiudad() && cantHabitantes == city.cantidadHabitantes() );
        }

	private:
		string nombre;
		int cantHabitantes;
		
};

#endif
