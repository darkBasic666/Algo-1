int main(int argc, char const *argv[])
{
	
	return 0;
}

int factoria(int n){
	//Local n
	int res = 1;
	//Estado PC
	//	vale n == pre(n) && pre(n) >= 0
	while(n>1){
		//Estado a
		//I:0 <= n <= pre(n) && res == prod((n .. pre(n)]) && n ==0 sii pre(n) == 0
		//V: n
		//Vale I && B
		res *= n;
		//Estado b
		// Vale res == res@a * n@a n == n@a
		n--;
		//Estado c
		// Vale n == n@b -1 && res == res@b
		//Implica n == n@a -1 && res == res@a * n@a
	}
	//Estado Qc
	// Vale res == prod([1 .. pre(n)]) 
	return res;
	// Estado Fin
	// Vale res == res @Qc
	// Implica res == fact(pre(n))
	

}