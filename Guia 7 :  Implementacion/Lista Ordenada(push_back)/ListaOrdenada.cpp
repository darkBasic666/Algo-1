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
	lo.push_back(e);
	lo.sort();
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
