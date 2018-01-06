#include "CsgDisk.h"

csgDisk::csgDisk(std::string label, Vec2d centre ,int rayon ) : csgPrimitive(label) {
    this->rayon = rayon;
    this->centre = centre;
    this->box = this->computeBoundingBox();
}

csgDisk::csgDisk(const csgDisk& copy) : csgPrimitive(copy) {
}


int csgDisk::getRayon()
{
    return this->rayon;
}

void csgDisk::setRayon(int rayon)
{
    this->rayon = rayon;
}


Vec2d csgDisk::getCentre()
{
    return this->centre;
}

void csgDisk::setCentre(const Vec2d &centre)
{
    this->centre = centre;
}


BoundingBox csgDisk::getBbox() const
{
    return this->box;
}

void csgDisk::setBbox(BoundingBox &box)
{
    this->box = box;
}


BoundingBox csgDisk::computeBoundingBox() {
    Vec2d max;
    max[0] = centre[0] + rayon;
    max[1] = centre[1] - rayon;

    Vec2d min;
    min[0] = centre[0] - rayon;
    min[1] = centre[1] + rayon;

    BoundingBox res;
    res.setMax(max);
    res.setMin(min);
    return res;
}

bool csgDisk::Intersect(Vec2d v) {
    int pyth = pow(v[0] - centre[0], 2) + pow(centre[1] - v[1], 2);
    if (sqrt(pyth) < rayon) {
        return true;
    } else {
        return false;
    }
}


void csgDisk::translation(Vec2d v) {
    Vec3d newVec;

    mat_transfo.translation(v[0],v[1]);
    //newVec = mat_transfo*Vec3d(centre[0],centre[1],((double)1.0)&);
    centre[0] = newVec[0]/newVec[2];
    centre[1] = newVec[1]/newVec[2];

    box = this->computeBoundingBox();
}
