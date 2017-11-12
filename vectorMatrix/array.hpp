/**
 * @author Nathan URBAIN
 * @date 3/11/2017
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "array.h"

// ---------------------------------------------------------------------
// Toute explicattions des différentes fonctions sont faites dans le .h
// Les tests d'Array sont présent dans le fichier testMatrix.cpp
// ---------------------------------------------------------------------



template<typename T, int N>
Array<T,N>::Array(){
    for(int i=0; i<N; i++){
        data[i] = T(0);
    }
}

template<typename T, int N>
Array<T,N> Array<T,N>::operator=(const Array<T,N>& tab){
    for(int i=0;i<N;i++){
        (*this)[i]=tab[i];
    }
    return *this;
}

template<typename T, int N>
T Array<T,N>::operator[](const int index) const{
    return data[index];
}


template<typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data[index];
}

template<typename T, int N>
const T* Array<T,N>::get_ptr() const{
    return data;
}


template<typename T, int N>
bool Array<T,N>::operator==(const Array<T,N>& tab){
    for(int i =0;i<N;i++){
        if((*this)[i] != tab[i]){
            return false;
        }
    }
    return true;
}

template<typename T, int N>
bool Array<T,N>::operator!=(const Array<T,N>& tab){

    for(int i =0;i<N;i++){
        if((*this)[i] != tab[i]){
            return true;
        }
    }
    return false;
}

//Fonction pouvant etre appellé sans instanciation d'un objet Array
template<typename T, int N>
void switchArray(Array<T,N>& tab1, Array<T,N>& tab2){
    for(int i=0;i<N;i++){
            T tmp = tab1[i];
            tab1[i] = tab2[i];
            tab2[i] = tmp;
    }
}


#endif
