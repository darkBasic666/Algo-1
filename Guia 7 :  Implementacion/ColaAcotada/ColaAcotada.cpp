#include <iostream>
#include "ColaAcotada.h"
using namespace std;
ColaAcotada::ColaAcotada (int n){
	capacidad = n;
	p  = 0;
	f = 0; 
	cola = new int[n];
	for (int i = 0; i < capacidad; ++i){
		cola[i] = 0;
	}
	
}
void ColaAcotada::show(){
	for (int i = 0; i < capacidad; ++i){
		cout << cola[i] << endl;
	}
}
void ColaAcotada::insertarAlFinal(int const e){
	//Estado E@0
	// Vale this.f == pre(this.f) &&  this.p == pre(this.p) && this.capacidad == pre(this.capacidad) &&
	// paraTodo(i←[0..this.f-this.p)) this.cola[this.p+i] == pre(this.cola[this.p+i])
	// Implica InvRep(this:ColaAcotada)
	// Implica abs(this:ColaAcotada,c:ColaAcotada)
	// Implica this.capacidad >= this.f - this.p + 1
	// Por el requiere del problema ( capacidad(c) >= |elementos(c)| + 1 )
	
	cola[f] = e;
	//Estado E@1
	// Vale this.cola[this.f]E@0 = e && this.f == this.fE@0 &&  this.p == this.pE@0 && this.capacidad == this.capacidadE@0 &&
	// paraTodo(i←[0..this.fE@0-this.pE@0)) this.cola[this.p+i] == this.cola[this.p+i]E@0
	// Implica this.f == pre(this.f) &&  this.p == pre(this.p) && this.capacidad == pre(this.capacidad) && 
	// paraTodo(i←[0..this.f-this.p)) this.cola[this.p+i] == pre(this.cola[this.p+i])
	f++;
	//Estado E@2
	// Vale this.cola[this.f]E@1 = e && this.f = this.fE@1 +1 &&  this.p == this.pE@1 && this.capacidad == this.capacidadE@1 &&
	// paraTodo(i←[0..this.fE@1-this.pE@1)) this.cola[this.p+i] == this.cola[this.p+i]E@1
	// Implica this.p == pre(this.p) && this.f == pre(this.f) + 1 && this.capacidad == pre(this.capacidad) && pre(this.cola[this.f]) = e
	// paraTodo(i←[0..pre(this.f)-pre(this.p))) this.cola[this.p+i] == pre(this.cola[this.p+i])
	// Implica InvRep(this:ColaAcotada): Porque
	// pre(this.f) == this.f - 1 , Como por el estado E@0
	// (this.capacidad >= pre(this.f) - this.p + 1) -> (this.capacidad >= this.f - this.p ) 
	// Implica abs(this:ColaAcotada,c:ColaAcotada)
	// Implica capacidad(c) == pre(capacidad(c))
	// Sabemos Que: |elementos(pre(c))| == pre(this.f)-pre(this.p)  == (this.f - this.c )-1 == |elementos(c)| - 1 
	// Implica |elementos(c)| == |elementos(pre(c))| + 1
	// Sabemos Que: paraTodo(i←[0..pre(this.f)-pre(this.p)-1)) this.cola[this.p+i] == pre(this.cola[this.p+i])
	// pre(this.f)-pre(this.p)-1 == |elementos(pre(c))| && this.cola[this.p+i] == elementos(c)[i]
	// Implica paraTodo(i←[0..|elementos(pre(c))|)) elementos(c)[i] == pre(elementos(c))[i]
	// Sabemos Que: (|elementos(pre(c))| == pre(this.f)-pre(this.p) && this.cola[this.p+i] == elementos(c)[i] && i == |elementos(pre(c))|)) →
	// this.cola[this.p +(pre(this.f)-pre(this.p))] == elementos(c)[|elementos(pre(c))|]
	// Conclucion : pre(this.cola[this.f]) == elementos(c)[|elementos(pre(c))|] == e
	// Implica elementos(c)[|elementos(pre(c))|] == e
}
int ColaAcotada::removerDelPrincipio(){
	//Estado E@0
	// Vale this.f == pre(this.f) &&  this.p == pre(this.p) && this.capacidad == pre(this.capacidad) &&
	// paraTodo(i←[0..this.f-this.p)) this.cola[this.p+i] == pre(this.cola[this.p+i])
	// Implica InvRep(this:ColaAcotada)
	// Implica abs(this:ColaAcotada,c:ColaAcotada)
	// Implica this.f-this.p >= 1 
	// Por el requiere del problema ( |elementos(c)| >=  1 )
	p++;
	//Estado E@1
	// Vale this.cola[this.f]E@0 = e && this.f == this.fE@0 &&  this.p == this.pE@0 + 1 && this.capacidad == this.capacidadE@0 &&
	// paraTodo(i←[0..this.fE@0-this.pE@0)) this.cola[this.p+i] == this.cola[this.p+i]E@0
	// Implica this.f == pre(this.f) &&  this.p == pre(this.p) + 1  && this.capacidad == pre(this.capacidad) && 
	// paraTodo(i←[0..this.f-this.p) this.cola[this.p+i] == pre(this.cola[this.p+i]))
	return cola[p - 1] ; 
	//Estado E@2
	// Vale this.cola[this.f]E@1 = e && this.f == this.fE@1 &&  this.p == this.pE@1 + 1 && this.capacidad == this.capacidadE@1 &&
	// && paraTodo(i←[0..pre(this.f)-pre(this.p))) this.cola[i] == this-cola[i]E@1 && result == this.cola[this.pE@1 -1]E@1
	// Implica this.f == pre(this.f) &&  this.p == pre(this.p) + 1  && this.capacidad == pre(this.capacidad) && 
	// paraTodo(i←[0..pre(this.f)-pre(this.p)) this.cola[this.p+i] == pre(this.cola[this.p+i])) && result == pre(this.cola[pre(this.p) -1])
	// Implica InvRep(this:ColaAcotada):Porque
	// pre(this.p) == this.p -1 
	// (this.f-pre(this.p) <= this.capacidad) -> (this.f-this.p - 1 <= this.capacidad)
	// Implica abs(this:ColaAcotada,c:ColaAcotada)
	// Implica capacidad(c) == pre(capacidad(pre(c)) 
	// Sabemos Que : (|elementos(pre(c))| == pre(this.f)-pre(this.p)  == (this.f - this.c )+1 == |elementos(c)| + 1) && (this.f-this.p >= 1 )
	// Implica |elementos(c)| == |elementos(pre(c)| -1 && |elementos(c)| >= 0
	// Sabemos Que : paraTodo(i←[0..pre(this.f)-pre(this.p)) this.cola[this.p+i] == pre(this.cola[this.p+i]))  && this.p == pre(this.p) + 1 && 
	// |elementos(pre(c))| == pre(this.f)-pre(this.p) 
	// Entonces: paraTodo(i←[0..|elementos(pre(c))|) this.cola[pre(this.p) + 1+i] == pre(this.cola[pre(this.p) + 1+i])) 
	// Que se deja escrbir asi: paraTodo(i←[1..|elementos(pre(c))|) this.cola[pre(this.p) +i] == pre(this.cola[pre(this.p) +i])) 
	// Implica paraTodo( i←[1..|elementos(pre(c))|) ) elementos(c)[i - 1] == elementos(pre(c))[i]
}