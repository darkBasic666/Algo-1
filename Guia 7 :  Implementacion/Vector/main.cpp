#include <iostream>
#include "Vector.cpp"

using namespace std;

int main()
{	
	Vector v(7,28.2);
    cout << "ordenada :" << v.ordenada()<< endl;
    cout << "abscisa :" << v.abcsisa()<< endl;
    return 0;
}
