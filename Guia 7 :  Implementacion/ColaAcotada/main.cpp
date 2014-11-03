#include <iostream>
#include "ColaAcotada.cpp"

using namespace std;

int main(){
	ColaAcotada c(5);
	c.insertarAlFinal(1);
	c.insertarAlFinal(2);
	c.insertarAlFinal(3);
	c.show();
	cout << c.removerDelPrincipio()<< endl;
	cout << c.removerDelPrincipio()<< endl;
	cout << c.removerDelPrincipio()<< endl;

	return 0;
}