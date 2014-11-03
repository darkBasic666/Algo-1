#ifndef VECTOR_H
#define VECTOR_H


class Vector
{
    public:
        Vector(float abscisa , float ordenada);
        float ordenada () const;
        float abscisa () const;
    private:
        float angulo  ;
        float radio ;
};

#endif // VECTOR_H
