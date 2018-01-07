#ifndef CSGDISK_H
#define CSGDISK_H

#include "csgPrimitive.h"
#include "../vectorMatrix/vector.h"


class csgDisk : public csgPrimitive{
public:
    Vec2d centre;
    int rayon;

    csgDisk(std::string label,Vec2d centre, int rayon);
    csgDisk(const csgDisk& copy);
    ~csgDisk(){}

    int getRayon();
    void setRayon(int rayon);

    Vec2d getCentre();
    void setCentre(const Vec2d &centre);

    BoundingBox getBbox() const;
    void setBbox(BoundingBox &box);

    BoundingBox computeBoundingBox();
    bool Intersect(Vec2d v);
    void translation(Vec2d v);

};


#endif
