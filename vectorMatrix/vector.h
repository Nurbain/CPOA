/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file vector function
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "../InterfaceCSG/Array.h"
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
     * @brief operator =, affectation by copy
     * @param v, vector with same Dimension and Type
     * @return Vector&
     */
    Vector& operator=(const Vector& v);

    /**
     * @brief operator ==, verification of eguality
     * @param v, vector with same Dimension and Type
     * @return true if vector equals
     */
    bool operator==(const Vector& v);

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
     * @brief scalar_product, compute the scalar product beetween 2 vector of same D and T
     * @param v, vector
     * @param u, vector
     * @return T number
     */
    T scalar_product(const Vector& v, const Vector& u);

    /**
     * @brief cross product for dimension 2
     */
    //typename std::enable_if<(D==2), Vector<D,T>>::type cross(const Vector<D,T>& u,const Vector<D,T>& v);

    /**
     * @brief cross product for dimension 3
     */
    typename std::enable_if<(D==3), Vector<D,T>>::type cross(const Vector<D,T>& u,const Vector<D,T>& v);

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


#include "vector.hpp"

#endif
