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
    void operator==(const Vector& v);

    Vector operator+(const Vector& v);
    Vector operator+=(const Vector& v);

    Vector operator-(const Vector& v);
    Vector operator-=(const Vector& v);

    Vector operator*(double f);
    Vector operator*=(double f);

    Vector operator/(double f);
    Vector operator/=(double f);

    double prod_scalaire(const Vector& v, const Vector& u);

    //TODO produit vectoriel
};


#include "vector.hpp"

#endif
