#include <list>
#include <vector>
class ListaOrdenada{
	// abs(this:TListaOrdenada,l:TListaOrdenada):
	// |this.lo| == longitud(l) ^  
	// paraTodo(i ← [0 |this.lo|)) valor(l,i) == this.lo[i]
	// InvRep(this:TListaOrdenada):
	// paraTodo(i ← [0..|this.lo|-1) this.lo[i] <= thi.lo[i + 1]
	public:
		ListaOrdenada();
		int valor(int) ;
		int longitud() const;
		void insertar(int);
		void show();
	private:
		int lon;
		void insert_at(int,int);
		std::list<int> lo;
};