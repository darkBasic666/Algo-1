int main(int argc, char const *argv[]){
	
	return 0;
}

bool hayAlgunCuadrado(int n , int m){
	int i = n , bool encontreUno = false;
	//Estado Pc
	// Vale i == n && encontreUno == false && n == pre(n) && m == pre(m) && n<=m
	while(i <= m && !encontreUno){
		//Estado Pif
		// I : n <= i <= m+1 && encontreUno == Exists( Pertenece(k,[n .. i) ) (esCuadrado(k))
		// V : m - i
		// Vale I && B && m == pre(m)
		if(esCuadrado(i)){
			//Estado if1
			// Vale esCuadrado(i@Pif) && i == i@Pif && m == m@pif
			encontreUno = true;
			// Vale i == i@if1 && encontreUno == true && m == m@if1
			// Implica esCuadrado(i@Pif) && m == pre(m)
		}
		//Estado Qif
		// Vale (esCuadrado(i@Pif) && encontreUno == true) || (!esCuadrado(i@Pif) && encontreUno == encontreUno@Pif)
		// &&  i == i@Pif && m == m@Pif 
		// Implica m == pre(m)
		i++;
		//Estado a
		// Vale i == i@Qif + 1 &&   (esCuadrado(i@Qif) && encontreUno == true) || (!esCuadrado(i@Qif) && encontreUno == encontreUno@Qif) && m == m@Qif 
		// Implica i == i@Pif + 1 && (esCuadrado(i@Pif) && encontreUno == true) || (!esCuadrado(i@Pif) && encontreUno == encontreUno@Pif) && m = pre(m)
	}
	//Estado Qc
	// Vale encontreUno == Exists( Pertenece(k,[n .. i) ) (esCuadrado(k))
	return encontreUno;
	// Vale result == encontreUno@Qc
	// Implica result == Exists( Pertenece(k,[n .. i) ) (esCuadrado(k))

}
