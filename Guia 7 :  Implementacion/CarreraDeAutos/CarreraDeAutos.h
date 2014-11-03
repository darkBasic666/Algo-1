#include <string> 
#include <list>
using namespace std;
class CarreraDeAutos{
	//abs(this:CarreraDeAutos,c:CarreraDeAutos):
	// conductores(c) == this.lc && |conductores(c)| == this.lc.size()
	// paraTodo(i← [0..this.lc.size())Existe(com ← competidores(c))posicion(c,com) == i 
	//InvRep(this:CarreraDeAutos):
	// paraTodo(i←[0 .. this.lc[i])) !Existe(j←[0..this.lc)[i]) (this.lc[i] == this.lc[j])&& (i != j)
	public:
		CarreraDeAutos(list<string>);
		list<string> ultimosTres() ;
		void pasarUnConductor(const string);
		void show(); 
	private:
   		list<string> lc;
   		int posicion(const string);
};