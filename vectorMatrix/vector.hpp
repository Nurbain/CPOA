/**
 * @author Nathan Urbain
 * @date 7/11/2017
 * @file fonctions de vecteur
 */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector.h"

template<int D,typename T>
void Vector<D,T>::operator=(const Vector<D,T>& v){
    for(int i;i<D;i++){
        this->data[i]=v[i];
    }
}

template<int D,typename T>
bool Vector<D,T>::operator==(const Vector<D,T>& v){
    for(int i; i<D; i++){
        if(this->data[i]!=v[i]){
            return false;
        }
    }
    return true;
}


template<int D,typename T>
Vector<D,T> Vector<D,T>::operator+(const Vector<D,T>& v){
    Vector<D,T> newVector = new Vector<D,T>();

    for(int i; i<D ; i++){
        newVector[i]= this->data[i]+v[i];
    }

    return newVector;
}

template<int D,typename T>
void Vector<D,T>::operator+=(const Vector<D,T>& v){
    for(int i=0; i<D ; i++){
        this->data[i] += v[i];
    }
}

template<int D,typename T>
Vector<D,T> Vector<D,T>::operator-(const Vector<D,T>& v){
    Vector<D,T> newVector = new Vector<D,T>();

    for(int i; i<D ; i++){
        newVector[i]= this->data[i]-v[i];
    }

    return newVector;
}

template<int D,typename T>
void Vector<D,T>::operator-=(const Vector<D,T>& v){
    for(int i; i<D ; i++){
        this->data[i] -= v[i];
    }
}

template<int D,typename T>
Vector<D,T> Vector<D,T>::operator*(double f){
    Vector<D,T> newVector = new Vector<D,T>();

    for(int i; i<D ; i++){
        newVector[i]= this->data[i]*f;
    }

    return newVector;
}

template<int D,typename T>
void Vector<D,T>::operator*=(double f){
    for(int i; i<D ; i++){
        this->data[i] *= f;
    }
}

template<int D,typename T>
Vector<D,T> Vector<D,T>::operator/(double f){
    Vector<D,T> newVector = new Vector<D,T>();

    for(int i; i<D ; i++){
        newVector[i]= this->data[i]/f;
    }

    return newVector;
}

template<int D,typename T>
void Vector<D,T>::operator/=(double f){
    for(int i; i<D ; i++){
        this->data[i] /= f;
    }
}

template<int D,typename T>
T produit_scalaire(const Vector<D,T>& v, const Vector<D,T>& u){
    T result;
    for(int i; i<D ;i++){
        result += v[i]*u[i];
    }

    return result;
}



#endif
