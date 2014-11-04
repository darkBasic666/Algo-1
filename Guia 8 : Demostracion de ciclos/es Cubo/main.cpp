int main(int argc, char const *argv[]){
	
	return 0;
}
bool esCubo(int n){
	//Estado 0
	//	Vale n == pre(n) 
	bool loEs = false;
	//Estado 1
	//	Vale n == n@0 && loEs == false
	//	Implica n == pre(n)
	int i = 0;
	//Estado Pif0
	//	Vale Vale n == n@1 && loEs == loEs@1 && i == 0
	// Implica n == pre(n) && loEs == false   
	if(n < 0)
		//Estado if0
		//	Vale Pif0 && n < 0 && i==i@Pif0 && loEs==loEs@Pif0
		n = -1*n;
		//Estado if1
		//	Vale n == -n@if1 && n@if1<0 && i==i@if0 && loEs==loEs@if0
		//	Implica n >= 0 &&  n == -pre(n) && i==0 && loEs==false
	//Estado Qif0
	//	Vale (n<0 && n == -pre(n)) || (n>=0 && n == pre(n)) && i==0 && loEs==false
	//	Implica n == abs(n) 
	i = n;
	//Estado Pc
	//	Vale i == n@Qif0 &&  loEs==loEs@Qif0 && n ==n@Qif0
	//	Implica i == abs(n) && n == abs(n) && loEs == false 
	while(i>0 && !loEs ){
		//Estado Pif1
		//	I: 0<= i <= abs(n) && loEs == Exists(In(k,(i .. abs(n)])) n == k^3
		//	V: i
		//	Vale I && B && n == n@Pc 
		//	Implica n == abs(n)
	 	if ( (i*i*i) == n {
	 		//Estado ifa
	 		//	Vale i^3 == n@Pif1 && n == n@Pif1 && i == i@Pif1
	 		//	Implica i^3 == abs(n) && n == abs(n)
	 		loEs == true;	
	 		//Estado ifb
	 		//	Vale loEs == true && n == n@if1 && i^3 == abs(n) && i == i@ifa
	 		//	Implica n ==(abs) && i == i@Pif1
	 	}
	 	//Estado Qif1
	 	//	Vale  (i^3 == abs(n) && loEs == true) || (i^3 != abs(n) && loEs == loEs@Pif1) && n == abs(n) i==i@Pif1
	 	i--;
	 	//Estado Fin
	 	//	Vale Qif1 && i == i@Qif1 - 1 && n == n@Qif1
	 	//	Implica i == i@Pif1 - 1 && n == n@Pif1
	}
	//Estado Qc
	//	Vale loEs == Exists(In(k,[0 .. abs(n)])) n == k^3 && n == n@Pc
	return loEs;
}
