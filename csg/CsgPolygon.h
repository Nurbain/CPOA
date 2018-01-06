#ifndef CSGPOLYGON_H
#define CSGPOLYGON_H

#include "csgPrimitive.h"

class csgPolygon : public csgPrimitive{
public:
    int nbface;
    Vec2d *tabSommet;

    csgPolygon(std::string label, int nbface);
    csgPolygon(const csgPolygon& copy);
    ~csgPolygon();


    Vec2d getSommet(int indice);
    void addSommet(Vec2d som);

    int getNbFace();
    void setNbFace(int nbface);


    BoundingBox computeBoundingBox();

    bool Intersect(Vec2d v);
    void translation(Vec2d trans);
    void rotation(float a);

    Vec2d getCoordBarycentre();

};

#endif
