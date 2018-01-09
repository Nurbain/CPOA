#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include "csgNode.h"
#include "matrix33d.h"

/**
 * @brief The csgPrimitive class, classe Abstraitre des primitive graphique
 */
class csgPrimitive : public csgNode {
public:
    //Matrix transformation de la primitive
    Matrix33d mat_transfo;

    csgPrimitive(std::string label);
     csgPrimitive(const csgPrimitive& copy);
    ~csgPrimitive(){}

     //Get/Set
     Matrix33d getMatrix();
     void setMatrix(Matrix33d mat);

     /**
      * @brief translation, translate la primitive
      * @param trans
      */
     virtual void translation(Vec2d trans) = 0;

     /**
      * @brief computeBoundingBox, calcule la boundinxBox
      * @return
      */
     virtual BoundingBox computeBoundingBox() = 0;

     /**
      * @brief IntersectBBox, Intersection du point avec la BoundingBox de la primtive
      * @param v, point
      * @return
      */
     bool IntersectBBox(Vec2d v);

};

#endif
