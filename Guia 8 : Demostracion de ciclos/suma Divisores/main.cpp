int main(int argc, char const *argv[]){
	return 0;
}
int sumaDivisores(int n){
	//Estado 0
	//	Vale n == pre(n) && n >= 1  
	int i = n,res = 0;
	//Estado Pc
	//	Vale i == 0 && res == 0 && n == n@0
	//	Implica n == pre(n) && n >= 1
	while(i>0){
		//Estado Pif:
		//	I: 1<= i<= n && sum([j|j←(i..n]])
		//	V: i
		//	Vale I && B && n == n@Pc
		//	Implica n == pre(n) 
		if(n % i == 0){
			//Estado if1
			//	Vale n@Pif  mod i@Pif == 0 && res == res @Pif && i == i@Pif && n == n@Pif
			res += i;
			// Vale n == n@if1 && res == res@if1 + i@if1 && i == i@if1 && 
			//Implica n@Pif  mod i@Pif == 0 && res == res@Pif + i@Pif  && i == i@Pif && n == n@Pif
		}
		//Estado Qif:
		//	Vale Q :((n mod i != 0) && (res == res@Pif)) || ((n mod i == 0) && (res == res@Pif + i@Pif)) 
		//	Vale i == i@Pif && n == n@Pif
		i--;
		//	Vale Q && n == n@Qif && i == i@Qif - 1
		//	Implica n == n@Pif && i == i@Pif - 1
	}
	//Estado Qc
	//	Vale res == sum([j|j←(1..n]])
	return res;
}