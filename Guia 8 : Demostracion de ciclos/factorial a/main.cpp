int main(int argc, char const *argv[])
{
	
	return 0;
}

int factorial(int n){
	//Estado 0
	// Vale n == pre(n) && n >= 0
	int i = 0 , res = 1;
	//Estado PC
	// Vale i = 0 && res = 1 n == n@0
	// Implica n == pre(n) && n >= 0
	while(i<n){
		//Estado a
		// I: 0 <= i <= n && res == fact(i)
		// V: n -i;
		// Vale I && B
		i++;
		//Estado b
		// Vale res == res@a && i == i@a + 1 
		res *= i;
		//Estado c
		// Vale res == res@b * i@b
		//Implica i== i@a +1 && res == res@a * i@a +1

	}
	//Estado QC
	// Vale  res == fact(n)   
	return res;
	// Estado Fin
	// Vale res == res@Qc
	// Implica res == fact(n)
}