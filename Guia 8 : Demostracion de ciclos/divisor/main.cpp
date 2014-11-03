int main(){
	
	return 0;
}

bool divisor(int n,int m){
	//local m 
	//Estado PC
	// Vale m == pre(m) n == pre(n)
	while(m >= n){
		// Estado 0
		// I : 0<= m <= pre(m) && m mod n == pre(m) mod n 
		// V : m
		n ++;
		//Estado 1
		// m == m@0 +1
	}
	//Estado QC
	// Vale Q: n == m && m == m@Pc
	// Implica m == pre(m)  
	return (m % n); 
	//Estado Fin
	// vale res == (m@Qc mod n@QC)
	// Implica m== pre(m) && n == pre(m) → (pre(m) mod pre(m) == 0)
	// Implica res == (m mod n == 0)
}