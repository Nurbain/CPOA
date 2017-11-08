/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file fonctions de vecteur
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "../InterfaceCSG/Array.h"
#include <assert.h>

template<int D, typename T>
class Vector : public Array<T,D>{

    public :
        Vector() : Array<T,D>(){}
        Vector(std::initializer_list<T> list)
        {
            assert(list.size() == D);
            int i = 0;
            for(int x: list)
                this->data[i++] = x;
        }

        Vector& operator=(const Vector& v);
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
using Vec2i = Vector<2,int>;
using Vec3i = Vector<3,int>;
using Vec4i = Vector<4,int>;

// Classe Float
using Vec2d = Vector<2,double>;
using Vec3d = Vector<3,double>;
using Vec4d = Vector<4,double>;




#include "vector.hpp"

#endif
