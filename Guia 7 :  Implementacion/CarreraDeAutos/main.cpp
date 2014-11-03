#include <iostream>
#include <string>
#include <list>
#include "CarreraDeAutos.cpp"
using namespace std;

int main(){
	list<string>  l;
	l.push_back("ivan");
	l.push_back("jorge");
	l.push_back("kamila");
	l.push_back("yo");
	CarreraDeAutos c( l);
	c.show();
	c.pasarUnConductor("yo");
	c.show();
	c.pasarUnConductor("yo");
	c.show();
	c.pasarUnConductor("yo");
	c.show();
	CarreraDeAutos tu(c.ultimosTres());
	tu.show();
	return 0;
}