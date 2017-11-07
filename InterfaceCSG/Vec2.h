/**
 * @author Nathan URBAIN
 * @date 06/09/2017
 */

#ifndef VEC2_H
#define VEC2_H

#include <cmath>
#include "Array.h"


template<typename T>
class Vec2 : public Array<T,2>{
    public :
        T norme() const;
        float prod_scalaire(const Vec2& v, const Vec2& u);
};

#include "Vec2.hpp"

#endif
