#include "csgPrimitive.h"

// ---------------------------------------------------------------------
// All explications for functions are in the file csgPrimitive.h
// ---------------------------------------------------------------------

csgPrimitive::csgPrimitive(std::string label) : csgNode(label) {
    mat_transfo = Matrix33d();
}


csgPrimitive::csgPrimitive(const csgPrimitive& copy) : csgNode(copy) {
    mat_transfo = copy.mat_transfo;
}

Matrix33d csgPrimitive::getMatrix() {
    return mat_transfo;
}

void csgPrimitive::setMatrix(Matrix33d mat) {
    mat_transfo = mat;
}

bool csgPrimitive::IntersectBBox(Vec2d v){
    Vec2d max = box.getMax();
    Vec2d min = box.getMin();

    if (v[0] > min[0] && v[0] < max[0]) {
        if (v[1] > max[1] && v[1] < min[1]) {
            return true;
        }
    }

    return false;
}
