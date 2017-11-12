/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file vector function
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file vector.h
// (Except for the cross product and overload of * operator, see end of file)
// Vector's test are in the file test_vec.cpp
// ---------------------------------------------------------------------

template<int D,typename T>
Vector<D,T> Vector<D,T>::operator+(const Vector<D,T>& v){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i]= (*this)[i]+v[i];
    }
    return newVector;
}


template<int D,typename T>
void Vector<D,T>::operator+=(const Vector<D,T>& v){
    for(int i=0; i<D ; i++){
        (*this)[i] += v[i];
    }
}


template<int D,typename T>
Vector<D,T> Vector<D,T>::operator-(const Vector<D,T>& v){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i]= (*this)[i]-v[i];
    }
    return newVector;
}


template<int D,typename T>
void Vector<D,T>::operator-=(const Vector<D,T>& v){
    for(int i=0; i<D ; i++){
        (*this)[i] -= v[i];
    }
}


template<int D,typename T>
Vector<D,T> Vector<D,T>::operator*(double f){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i]= (*this)[i]*f;
    }
    return newVector;
}


template<int D,typename T>
void Vector<D,T>::operator*=(double f){
    for(int i=0; i<D ; i++){
        (*this)[i] *= f;
    }
}


template<int D,typename T>
Vector<D,T> Vector<D,T>::operator/(double f){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i] = (*this)[i]/f;
    }
    return newVector;
}


template<int D,typename T>
void Vector<D,T>::operator/=(double f){
    for(int i=0; i<D ; i++){
        (*this)[i] /= f;
    }
}


template<int D,typename T>
Vector<D,T> operator*(double f, const Vector<D,T>& v){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i]= v[i]*f;
    }
    return newVector;
}


//------------------------------------------------------
// Here function who aren't in .h


/**
 * @brief Overload * operator to do  V = 0.5f * V
 */
template<int D,typename T>
T Vector<D,T>::operator* (const Vector<D,T>& v){
    T result;
    for(int i=0; i<D ;i++){
        result += (*this)[i]*v[i];
    }
    return result;
}

/**
 * @brief Cross product for 2 dimension vector
 * @param u, first vector
 * @param v, second vector
 * @return T
 */
template<int D, class T>
typename std::enable_if<(D == 2), T >::type cross(const Vector<D,T>& u, const Vector<D,T>& v){
    T resultat;
    resultat = u[0]*v[1]-v[0]*u[1];
    return resultat;
}

/**
 * @brief Cross product for 3 dimension vector
 * @param u, first vector
 * @param v, second vector
 * @return Vector<3,T>
 */
template<int D, class T>
typename std::enable_if<(D == 3), Vector<D, T> >::type cross(const Vector<D,T>& u, const Vector<D,T>& v){
    Vector<D,T> newVector;
    newVector[0]=u[1]*v[2]-u[2]*v[1];
    newVector[1]=u[2]*v[0]-u[0]*v[2];
    newVector[2]=u[0]*v[1]-u[1]*v[0];
    return newVector;
}

#endif
