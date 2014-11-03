#include "Ciudad.h"
#include "Mapa.h"

#include <iostream>
#include <vector>
#include <cstdio>

#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
	string infile(argv[1]);
    string outfile(argv[2]);

    ifstream in(infile.c_str());

    Mapa mapaActual;
	mapaActual.leerMapa(in);

    ofstream out(outfile.c_str());
    mapaActual.imprimirMapa(out);
    out.close();

	return 0;
}
