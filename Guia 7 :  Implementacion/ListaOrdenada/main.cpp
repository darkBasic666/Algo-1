#include <iostream>
#include <vector>
#include "ListaOrdenada.cpp"

using namespace std;

int main()
{	
 	ListaOrdenada lo;
 	lo.insertar(1);
 	lo.insertar(2);
 	lo.insertar(1);
 	lo.show();
 	cout<< " "<<lo.longitud()<<endl;
 	
   return 0;
}
