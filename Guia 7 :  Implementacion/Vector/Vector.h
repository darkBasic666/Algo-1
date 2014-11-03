class Vector{
	// abs (imp : Vector , esp: Vector):
	// abscisa(esp) == imp.radio * coseno(imp.angulo)
	// ordenad(esp) == imp.radio * seno(imp.angulo)
	// invRep(imp: Vector):
	// True
	public:
	Vector(float, float);
	float abcsisa() const;
	float ordenada() const;
	private:
	float radio;
	float angulo;
};