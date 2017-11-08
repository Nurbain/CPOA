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
class Vec2i : public Vector<2,int>{
    public:
        Vec2i() : Vector<2,int>() {}
        Vec2i(std::initializer_list<int> list): Vector<2,int>(list){}
};
class Vec3i : public Vector<3,int>{
    public:
        Vec3i() : Vector<3,int>() {}
        Vec3i(std::initializer_list<int> list): Vector<3,int>(list){}
};
class Vec4i : public Vector<4,int>{
    public:
        Vec4i() : Vector<4,int>() {}
        Vec4i(std::initializer_list<int> list): Vector<4,int>(list){}
};

// Classe Float
class Vec2d : public Vector<2,double>{
    public:
        Vec2d() : Vector<2,double>() {}
        Vec2d(std::initializer_list<double> list): Vector<2,double>(list){}
};

using Vec3d = Vector<3,double>;

class Vec4d : public Vector<4,double>{
    public:
        Vec4d() : Vector<4,double>() {}
        Vec4d(std::initializer_list<double> list): Vector<4,double>(list){}
};


#include "vector.hpp"

#endif
