
class ColaAcotada{
	//InvRep(this:ColaAcotada):
	// this.f-this.p <= this.capacidad 
	//abs(this:ColaAcotada,c:ColaAcotada):
	// this.capacidad == capacidad(c) && |elementos(c)| == this.f-this.p
	// paraTodo (i←[0..|elementos(c)|)) this.cola[this.p+i] == elementos(c)[i]
	public:	
		ColaAcotada(int);
		void insertarAlFinal(int const);
		int removerDelPrincipio();
		void show();
	private:
		int capacidad;
		int p;
		int f;
		int *cola;
};
