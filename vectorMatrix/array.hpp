/**
 * @author Nathan URBAIN
 * @date 06/09/2017
 * @code fonctions Array.h
 */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "array.h"


/**
 * @brief Constructeur
 */
template<typename T, int N>
Array<T,N>::Array(){
    for(int i=0; i<N; i++){
        data[i] = T(0);
    }
}

/**
 * @brief   methode qui return l'element d'index donné
 * @return  {T}  element du tableau
 */
template<typename T, int N>
T Array<T,N>::operator[](const int index) const{
    return data[index];
}


/**
 * @brief   methode qui return l'element d'index donné
 * @return  {T&} adresse de l'element du tableau
 */
template<typename T, int N>
T& Array<T,N>::operator[](const int index){
    return data[index];
}

template<typename T, int N>
Array<T,N> Array<T,N>::operator=(const Array<T,N>& tab){
    for(int i=0;i<N;i++){
        (*this)[i]=tab[i];
    }
    return *this;
}

/**
 * @brief   methode qui return data
 * @return  {T*}
 */
template<typename T, int N>
const T* Array<T,N>::get_ptr() const{
    return data;
}

/**
 * @brief   methode qui verifie si le tableau est identique a celui donné
 * @return  {bool}
 */
template<typename T, int N>
bool Array<T,N>::operator==(const Array<T,N>& tab){
    for(int i =0;i<N;i++){
        if((*this)[i] != tab[i]){
            return false;
        }
    }
    return true;
}

/**
 * @brief   methode qui verifie si le tableau est différent a celui donné
 * @return  {bool}
 */
template<typename T, int N>
bool Array<T,N>::operator!=(const Array<T,N>& tab){

    for(int i =0;i<N;i++){
        if((*this)[i] != tab[i]){
            return true;
        }
    }
    return false;
}

/**
 * @brief   methode qui echange avec le tableau donné
 * @return  {bool}, vrai si opération réussi
 */
template<typename T, int N>
Array<T,N> Array<T,N>::switchArray(const Array<T,N>& tab){
    Array<T,N> newArray = Array();
    for(int i=0;i<N;i++){
        newArray[i]=tab[i];
    }
    return newArray;
}


#endif
