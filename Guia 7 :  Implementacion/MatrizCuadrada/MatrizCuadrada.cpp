#include <iostream>
#include "MatrizCuadrada.h"
using namespace std;

MatrizCuadrada::MatrizCuadrada(int d){
	dim = d;
	valores = vector<vector<int> >  (d,vector<int> (d));
	for (int i = 0; i < dim; ++i){
		for (int j = 0; j < dim; ++j){
			valores.at(i).at(j) = (dim * i) + j;
		}
	}
}
int MatrizCuadrada::dimension() const{
	return dim;

}
int MatrizCuadrada::valor(int const i , int const j) const{
	
	return valores.at(i).at(j);

}
void MatrizCuadrada::cambiarValor(int const f ,int const c, int  const nv){
	// Estado E@0
	// Implica paraTodo( i ← [0..dim),j ← [0..dim) )  this.valores[i][j] == pre(this.valores[i][j]) 
	// Implica InvRep(this)
	// Implica abs (this,mt):
	//	f == fila ^ c == columna ^ nw == nuevoValor 
	// Implica 0 <= f < dim
	// Implica 0 <= c < dim
	valores.at(f).at(c) = nv;
	// Estado E@1
	// Vale this[f][c] == nv 
	// Implica paraTodo( i ← [0..dim),j ← [0..dim) , i != f ^ j != c)  this.valores[i][j] == pre(this.valores[i][j]) 
	// Implica InvRep (this) : (se sigue cumpliendo q)
 	// |this.valores| == this.dim ^ |this.valores| >= 1 ^ |this.valores| ==  |this.valores[f]|
	// Implica abs(this,mt):
	// Implica paraTodo( i ← [0..dimesion(mt)) , j ← [0..dimesion(mt)) , (i != fila) ^ ( j != columna) ) valor(mt, i,j) == valor(pre(mt),i,j)
	// Implica valor(mt,fila,columna) == nuevoValor 
}
void MatrizCuadrada::show ()const{
	for (int i = 0; i < dim ; ++i){
		for (int j = 0; j < dim; ++j){
			cout << valores.at(i).at(j) << " ";
		}
		cout<< endl;
	}

}