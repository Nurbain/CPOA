#ifndef CSGPRIMITIVE_H
#define CSGPRIMITIVE_H

#include "csgNode.h"
#include "matrix33d.h"

class csgPrimitive : public csgNode {
public:
    Matrix33d mat_transfo;

    csgPrimitive(std::string label);
     csgPrimitive(const csgPrimitive& copy);
    ~csgPrimitive(){}

     Matrix33d getMatrix();
     void setMatrix(Matrix33d mat);

     virtual void translation(Vec2d trans) = 0;
     virtual BoundingBox computeBoundingBox() = 0;
     bool IntersectBBox(Vec2d v);

};

#endif
