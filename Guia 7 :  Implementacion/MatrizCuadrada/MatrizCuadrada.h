#include <vector>
using namespace std;
class MatrizCuadrada{
	// abs(this:MatrizCuadrada,m:MatrizCuadrada):
	// |this.valores| == dimension(m) ^ 
	// paraTodos( f←[0..|this.valores|))paraTodos(c←[0..|this.valores|)
	// valor(m,f+1,c+1) == this.valores[f][c]
	// InvRep(this:MatrizCuadrada):
	// |this.valores| == this.dim ^ |this.valores| >= 1 ^ |this.valores| ==   |this.valores[f]|
	public:
		MatrizCuadrada(int);
		int dimension() const;
		int valor (int ,int ) const;
		void cambiarValor(int,int,int);
		void show()const;
	private:
		int dim;
		vector<vector<int> > valores ;
	
};