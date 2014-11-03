#include "CarreraDeAutos.h"
#include <iostream>
#include <string>
#include <list>
using namespace std;

CarreraDeAutos::CarreraDeAutos(list<string> auxLC ){
	lc = auxLC;
}
void CarreraDeAutos::show(){
	list<string>::iterator it;
	for (it=lc.begin(); it!=lc.end(); ++it)
    	std::cout << *it << endl;
  	std::cout << '\n';
}
list<string> CarreraDeAutos::ultimosTres() {
	list<string> r;
	list<string>::reverse_iterator rit = lc.rbegin();
	int i = (lc.size() -1);
	
	for (; i>=(lc.size() - 3); --i){
		r.push_back(*rit);
		++rit;
	}
	return r;
}

void CarreraDeAutos::pasarUnConductor(string const conductor){
	//Estado E@0
	// Vale this.lc == pre(this.lc)
	// Implica InvRep(this:CarreraDeAutos)
	// Implica abs(this:CarreraDeAutos,c:CarreraDeAutos):
	//Por los requiere de la especificion
	// Sabemos Que: conductor pertenece  conductor(c) && posicion(c,conductor) > 1 
	// Implica conductor pertenece a this.lc && this.posicion(conductor) > 1
	list<string> m;
	//Estado E@1
	// Vale m == {} && this.lc == this.lcE@0
	// Implica this.lc == pre(this.lc)
	list<string>::iterator it = lc.begin();
	//Estado E@2
	// Vale it == this.lc[0] && this.lc == this.lcE@1 && m == E@1
	// Implica this.lc == pre(this.lc) && m == {}
	int i =0;
	//Estado E@3
	// Vale it == itE@2 && this.lc == this.lcE@2 && m == E@2 && i == 0
	// Implica this.lc == pre(this.lc) && it ==this.lc[0] && m == {}
	int p = posicion(conductor);
	//Estado PC@0:
	// Vale it == itE@3 && this.lc == this.lcE@3 && m == E@3 && i == E@3 &&
	// Existe(p←[0..this.lc.size())) this.lc[p] == conductor
	// Implica this.lc == pre(this.lc) && it ==this.lc[0] && m == {} 
	while (it!=lc.end()){
		if(i==p-1){
			string aux = *it;
			i++;
			++it;
			m.push_back(*it);
			m.push_back(aux);
		}else{
			m.push_back(*it);
		}
		i++;
		++it;
	}
	//Estado QC@0:
	// Vale it == this.lc[this.lo.size()] && i == this.lo.size() && p == pPC@0
	// paraTodo(i←[0..this.lo.size()), (i > p) && (i< p -1)) m[i] ==  (this.lc)Pc@0[i] &&
	// m[p] == (this.lc)Pc@0[p-1] && m[p-1] == (this.lc)Pc@0[p]  && m.size() == (this.lc)PC@0.size()
	// &&  this.lc == (this.lc)PC@0
	// Implica paraTodo(i←[0..this.lo.size()), (i > p) && (i< p -1)) m[i] ==  pre(this.lc)[i] && 
	// Existe(p←[0..this.lc.size())) this.lc[p] == conductor &&
	// m[p] == pre(this.lc)[p-1] && m[p-1] == pre(this.lc)[p]  && m.size() == pre(this.lc).size() && 
	// this.lc == pre(this.lc)
	lc = m;
	//Estado E@4
	// Vale this.lc == mQC@0 && p == pQC@0
	// Implica Existe(p←[0..this.lc.size())) this.lc[p] == conductor &&
	// paraTodo(i←[0..this.lo.size()), (i > p) ||(i< p -1)) this.lc[i] ==  pre(this.lc)[i] &&
	// this.lc[p] == pre(this.lc)[p-1] && this.lc[p-1] == pre(this.lc)[p]  && this.lc.size() == pre(this.lc).size()
	// Implicar Que :(paraTodo(cond ← pre(this.lc)) cond pertenece  this.lc )&& (paraTodo(cond ← this.lc) cond pertenece pre(this.lc) )
	// Entoces :paraTodo(i←[0 .. this.lc.size())) Existe(j←[0..this.lc.size())) (this.lc[i] == this.lc[j])&& (i == j)
	// Implica InvRep(this:CarreraDeAutos)
	// Implica abs(this:CarreraDeAutos,c:CarreraDeAutos):
	// Sabemos Que : this.lc.size() == pre(this.lc).size()
	// Implica |conductores(c)| == |conductores(pre(c))| 
	// Sabemos Que : Existe(p←[0..this.lc.size())) this.lc[p] == conductor &&
	// paraTodo(i←[0..this.lo.size()), (i > p) || (i< p -1)) this.lc[i] ==  pre(this.lc)[i] 
	// Implica paraTodo(con ← conductores(c), (posicion(pre(c),con) > posicion(c,condcutor) )|| (posicion(pre(c),con) < posicion(c,condcutor) -1 ))
	// posicion(c,con) == posicion(pre(c),con) 
	// Sabemos Que : this.lc[p] == pre(this.lc)[p-1]
	// Implica posicion(c,conductor) == posicion(pre(c),conductor) - 1
	// Sabemos Que : pre(this.lc)[p-1] == this.lc[p] && Existe(p←[0..this.lc.size())) this.lc[p] == conductor 
	// Implica Existe(con ← conductores)(posicion(pre(c),con) == posicion(pre(c),conductor) -1 )&&(posicion(c,con) == posicion(pre(c),conductor) 
}
int CarreraDeAutos::posicion(string const conductor){
	//Estado E@0
	// Vale conductor pertenece a this.lc && this.posicion(conductor) > 1 && this.lc == pre(this.lc)
	list<string>::iterator it = lc.begin();
	//Estado E@1
	// vale it == lc.lc[0] && this.lc == this.lcE@1
	// Implica this.lc == pre(this.lc)
	int i =0;
	//Estado PC@0
	// Vale i === 0 &&  it == ir E@1
	// Implica it == lc.lc[0] && this.lc == pre(this.lc)
	while (*it != conductor){
		i++;
		++it;
	}
	//Estado QC@0
	// Vale it == conductor && Existe(i←[0..this.lc.size())) this.lc[i] == conductor
	// Implica it == this.lc[i] && this.lc == pre(this.lc)
	return i;
	
}