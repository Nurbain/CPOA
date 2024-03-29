/**
 * @author Nathan URBAIN
 * @date 06/09/2017
 */

#ifndef ARRAY_H
#define ARRAY_H

/**
 * @class Array
 * @brief Classe template de tableau de type N
 *
 * @protectedsection
 *      @property {T}   data, tableau
 *
 * @publicsection
 *      {T}     operator[], methode qui return l'element d'index donné
 *      {T*}    get_ptr, return data
 *      {bool}  operator== , verifie si le tableau donné est identique
 *      {bool}  operator!= , verifie si le tableau donné est différent
 *      {bool}  switchArray, echange de 2 tableau
 */
template <typename T, int N>
class Array{
    protected :
        T data[N];
    public :
        Array();
        T operator[](const int index) const;
        T& operator[](const int index);
        const T* get_ptr() const;
        bool operator==(const Array& Tab);
        bool operator!=(const Array& Tab);
        bool switchArray(const Array& Tab);
};


#include "Array.hpp"

#endif
