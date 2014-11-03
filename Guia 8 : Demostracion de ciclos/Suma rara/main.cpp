#include <iostream>

using namespace std;

int main(){
	
	cout << sumaRara(10,1);
	return 0;
}
int sumaRara(int const n,int  k){
	// Estado E1
	// Vale n >= 0 && k == pre(k) && n == pre(n)
	int res = 0;
	// Estado E2
	// Vale  n >= 0 && k == k@1 && n == n@1 && res == 0
	// Implica k == pre(k) && n == pre(n)
	int i = 0;
	// Estado PIF
	// Vale  n >= 0 && k == k@2 && n == n@2 && res == res@2 && i == 0
	// Implica k == pre(k) && n == pre(n) && res == 0
	if(k % 2 == 1)
		k ++;
	// Estado QIF o PC
	// Vale n >= 0 && n == n@PIF && res == res@PIF && i == i@PIF && 
	// (k mod 2 == 1 && k == k@PIF + 1) || k ==  k@PIF
	// Entonces k = pre(k) + (pre(k) mod 2) quiere decir el numero par mas cercano a k  
	// Implica   i == 0 && n == pre(n) && res == 0 && k == parMasCercano(k)
	while( i< n){
		// Estado Ea
		// I:0<=i<=n && res == sum([j*k| j←[0 .. i))
		// V = n - i 
		// Vale I && B  && n == n@PC && k == parMasCercano(k)
		res += i*k;
		// Estado Eb
		// Vale res == res@a + i*k && i = i@a n == n@a && k == k@a
		i++;
		// Estado Ec
		// Vale res == res@b && i = i@b +1 && n == n@b && k == k@b
		// Implica res == res@a + i*k && i = i@a + 1 && n == pre(n) && n >= 0 && k == parMasCercano(k)
		// (i@a < n && i == i@a +1 ) → (i@a + 1 <= n) → (0<= i <= n)
		// res@a == sum([j*parMasCercano(k)| j←[0 .. i@a))
		// res == sum([j*parMasCercano(k)| j←[0 .. i@a)) + ((i@a +1) *parMasCercano(k)) →
		// res == sum([j*parMasCercano(k)| j←[0 .. i@a +1 )) →
		// res == sum([j*parMasCercano(k)| j←[0 .. i))
	}
	// Estado QC
	// vale k == k@QIF && res == sum([j*k| j←[0 .. n))
	// Implica res == sum([j*parMasCercano(k)| j←[0 .. n))
	return res;
}