/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file vector function
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "array.h"
#include <assert.h>
#include <iostream>

/**
 * @class Vector
 * @brief Classe template who define Vector
 * @property Defined by a Dimension(2,3,4) and Type(int,double)
 */
template<int D, typename T>
class Vector : public Array<T,D>{

public :

    /**
     * @brief Vector, Empty Constructor
     */
    Vector() : Array<T,D>(){}

    /**
     * @brief Vector, Constructor by list
     * @param list, list of elements
     */
    Vector(std::initializer_list<T> list)
    {
        assert(list.size() == D);
        int i = 0;
        for(int x: list)
            this->data[i++] = x;
    }

    /**
     * @brief operator +, sum with a vector for a third vector
     * @param v, vector with same Dimension and Type
     * @return  new sum of the 2 vector
     */
    Vector operator+(const Vector& v);

    /**
     * @brief operator +=, sum with himself and a vector
     * @param v, vector with same Dimension and Type
     */
    void operator+=(const Vector& v);


    /**
     * @brief operator -, soustraction with a vector for a third vector
     * @param v, vector with same Dimension and Type
     * @return  new soustraction of the 2 vector
     */
    Vector operator-(const Vector& v);

    /**
     * @brief operator -=, soustraction with himself and a vector
     * @param v, vector with same Dimension and Type
     */
    void operator-=(const Vector& v);


    /**
     * @brief operator *, product with a double for a second vector
     * @param f, double
     * @return new vector
     */
    Vector operator*(double f);

    /**
     * @brief operator *=, product with himself and a double
     * @param f, double
     */
    void operator*=(double f);

    /**
     * @brief operator /, division with a double for a second vector
     * @param f, double
     * @return new vector
     */
    Vector operator/(double f);

    /**
     * @brief operator /=, division with himself and a double
     * @param f, double
     */
    void operator/=(double f);

    /**
     * @brief operator *, dot product
     * @param v, second vecteur for product
     * @return T , dot
     */
    T operator*(const Vector& v);

    /**
     * @brief operator <<, display vector object
     * @param os, stream to return
     * @param v, vector to display
     * @return os, stream with all data from vector
     */
    inline friend std::ostream& operator<<(std::ostream& os, const Vector<D,T>& v){
       for(int i=0;i<D;i++){
        os << v[i] << " ";
       }
       return os;
    }
};



// Int Vector explicit declaration with Dimension 2,3,4
using Vec2i = Vector<2,int>;
using Vec3i = Vector<3,int>;
using Vec4i = Vector<4,int>;

// Float Vector explicit declaration with Dimension 2,3,4
using Vec2d = Vector<2,double>;
using Vec3d = Vector<3,double>;
using Vec4d = Vector<4,double>;

using Vec3uc = Vector<3,unsigned char>;

#include "vector.hpp"

#endif
