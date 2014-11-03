#include "Vector.h"
#include <cmath>

using namespace std;

Vector::Vector(float const x , float const y){
	// Estado E@0
	// implica invRep 
	angulo = atanf(y/x);
	// Estado E@1
	// vale angulo == arcoTangente(y/x)
	radio = sqrtf(powf(x,2) + powf(y,2));
	// Estado E@2
	// vale radio ==  (x² + y²)⁽¹/²⁾
	// Por Pitagoras vale que el radio es la raiz de la suma del cudrado de los catetos
	// Por la traducion de cordenadas polares .
	// y es la abscisa , x es la ordenada
	// implica abscisa(esp) == imp.radio * coseno(imp.angulo)
	// implica ordenada(esp) == imp.radio * seno(imp.angulo)
	// implica abs (this , v)
}

float Vector::abcsisa() const{
	return radio * sinf(angulo);
}

float Vector::ordenada() const{
	return radio * cosf(angulo);
}