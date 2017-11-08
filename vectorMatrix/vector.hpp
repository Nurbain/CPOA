/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file vector function
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

// All function signature are details in the header


template<int D,typename T>
Vector<D,T>& Vector<D,T>::operator=(const Vector<D,T>& v){
    for(int i=0;i<D;i++){
        (*this)[i]=v[i];
    }
    return *this;
}


template<int D,typename T>
bool Vector<D,T>::operator==(const Vector<D,T>& v){
    for(int i=0; i<D; i++){
        if((*this)[i]!=v[i]){
            return false;
        }
    }
    return true;
}


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
T scalar_product(const Vector<D,T>& v, const Vector<D,T>& u){
    T result;
    for(int i=0; i<D ;i++){
        result += v[i]*u[i];
    }
    return result;
}


template<int D,typename T>
Vector<D,T> operator*(double f, const Vector<D,T>& v){
    Vector<D,T> newVector;
    for(int i=0; i<D ; i++){
        newVector[i]= v[i]*f;
    }
    return newVector;
}

#endif
