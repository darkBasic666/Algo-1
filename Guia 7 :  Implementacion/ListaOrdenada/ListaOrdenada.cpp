#include <iostream>
#include <list>
#include "ListaOrdenada.h"
using namespace std;

ListaOrdenada::ListaOrdenada(){
	lon = 0;
	lo =  std::list<int> (0);

}
int ListaOrdenada::longitud()const{
	return lo.size();
}
int ListaOrdenada::valor(int n) {
	std::list<int>::iterator it;
	int result;
	int i = 0;
	for (it=lo.begin(); it!=lo.end(); ++it){
	    if (i == n){
	    	result = *it;
	    }
	    i++;
	}
	
	return result;
}
void ListaOrdenada::insertar(int e){
	//Estado E@0
	//Implica InvRep(this)
	//Implica abs(this,l)
	std::list<int>::iterator it = lo.begin();
	//Estado E@1
	// Vale it == this.lo [0];
	int i = 0;
	//Estado PC: 
	// Vale i == 0;
	// Implica it == itE@1
	while( e > *it && i < longitud() ){
		i++;
		++it;
	}
	//Estado QC:
	// Vale paraTodo(j ← [0 .. i))this.lo[j] <= e
	// Vale paraTodo(j ← [i this.longitud()) e <= this.lo[j]
	// Vale it == this.lo[i]
	insert_at(i,e);
	//Estado E@2
	// Vale this.longitud == pre(this.longitud) + 1 
	// Vale this[i] == e
	// Vale paraTodo(j ← [0 .. i))this.lo[j] == pre(this[j])
	// Vale paraTodo(j ← (i this.longitud()) this.lo[j] == pre(this.lo[j-1])
	
	// Implica i == i@QC
	// Implica InvRep(this:TListaOrdenada): 
	// Porque  (E@2  && E@1)-> paraTodo(i ← [0..|this.lo|-1) this.lo[i] <= thi.lo[i + 1] 
	// Como el elemento e q voy a insertar , lo voy a insertar en una posicion tal q el siguiente es mayor igual y el anterior menor igual (E@2)
	// Dsp de insetarlo (E@2) sigue estando ordenada la lista.
	// Implica abs(this:TListaOrdenada,l:TListaOrdenada)
	// Implica longitud(l) == longitud(pre(l))
	// Implica (i == ins) ^ (ins pertenece [0 .. longitud(pre(l))]) 
	// ^ paraTodo(i ← [0 .. ins)) (valor(pre(l),i) <= e) ^ (valo(l,i) == valor(pre(l),i))
	// ^ paraTodo(i ← (ins .. longitud(l)]) (valor(pre(l),i-1) >= e) ^ (valor(l,i) == valor(pre(l),i -1))
	// ^ valor(l,ins) == e
}
void ListaOrdenada::insert_at(int i ,int e){
	std::list<int>::iterator it = lo.begin();
	for (; i > 0 ; ++it ,--i){}
	lo.insert(it,e);
	
}
void ListaOrdenada::show(){
	std::list<int>::iterator it;
	for (it=lo.begin(); it!=lo.end(); ++it)
    	std::cout << ' ' << *it;
  std::cout << '\n';
}
