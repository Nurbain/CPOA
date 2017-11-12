/**
 * @author Nathan URBAIN
 * @date 3/11/2017
 */

#ifndef ARRAY_H
#define ARRAY_H

#include <assert.h>
#include <iostream>

/**
 * @class Array
 * @brief Classe template de tableau de type T et taille N
 * @property {T}   data
 */
template <typename T, int N>
class Array{
    protected :
        T data[N];

    public :
        /**
         * @brief Empty constructor
         */
        Array();

        /**
         * @brief constructeur par liste
         * @param list des données
         */
        Array(std::initializer_list<T> list)
        {
            assert(list.size() == N);
            int i = 0;
            for(int x: list)
                this->data[i++] = x;
        }

        /**
         * @brief operator =, operateur d'affectation
         * @param array
         * @return this
         */
        Array<T,N> operator=(const Array<T,N>& array);

        /**
         * @brief operator [], operateur d'accesseurs
         * @param index, index de la donné a récuperer
         * @return T
         */
        T operator[](const int index) const;

        /**
         * @brief operator [], operateur de modification par accés []
         * @param index, index de la donné a modifier
         * @return
         */
        T& operator[](const int index);

        /**
         * @brief get_ptr, return data
         * @return data
         */
        const T* get_ptr() const;

        /**
         * @brief operator ==, operateur d'egalité
         * @param Tab, array comparé
         * @return true si egale
         */
        bool operator==(const Array<T,N>& tab);

        /**
         * @brief operator =!, operateur de différence
         * @param Tab, array comparé
         * @return true si différent
         */
        bool operator!=(const Array<T,N>& tab);

        /**
         * @brief switchArray, echange les 2 arrays donné en argument
         * @param tab1, 1er tableau
         * @param tab2, second tableau
         * @note Absence de const parce que modification des tableaux
         */
        void switchArray(Array<T,N>& tab1, Array<T,N>& tab2);
};

//Include de l'implementation des fonctions
#include "array.hpp"

#endif
