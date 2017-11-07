/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file fonctions de vecteur
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "../InterfaceCSG/Array.h"

template<int D, typename T>
class Vector : public Array<T,D>{

    void operator=(const Vector& v);
    bool operator==(const Vector& v);

    Vector operator+(const Vector& v);
    void operator+=(const Vector& v);

    Vector operator-(const Vector& v);
    void operator-=(const Vector& v);

    Vector operator*(double f);
    void operator*=(double f);

    Vector operator/(double f);
    void operator/=(double f);

    T prod_scalaire(const Vector& v, const Vector& u);

    //TODO produit vectoriel
};


// Classe Int
class Vec2i : public Vector<2,int>{};
class Vec3i : public Vector<3,int>{};
class Vec4i : public Vector<4,int>{};

// Classe Float
class Vec2d : public Vector<2,double>{};
class Vec3d : public Vector<3,double>{};
class Vec4d : public Vector<4,double>{};


#include "vector.hpp"

#endif
