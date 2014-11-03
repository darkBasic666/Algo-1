#include <iostream>
#include <vector>
#include "MatrizCuadrada.cpp"
using namespace std;

int main()
{	
  MatrizCuadrada mc(3);
  cout << "pos 1 , 2 :" << mc.valor(1,2) << endl;
  mc.show();
  cout << endl;
  mc.cambiarValor(0,0,8);
  mc.show();
   return 0;
}
