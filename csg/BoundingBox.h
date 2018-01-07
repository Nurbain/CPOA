/**
 * @author Nathan Urbain
 * @date 22/11/2017
 */


#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H


#include "../vectorMatrix/vector.h"

class BoundingBox{

protected:
    //  y  _____p2
    //  | |      |
    //  | |      |
    //  | p1_____|
    //  |____________x
    //
    //

    Vec2d pointMin;
    Vec2d pointMax;
    float largeur;
    float hauteur;


public:
    BoundingBox();
    BoundingBox(const float px, const float py, const float qx, const float qy) {
        pointMin = {px,py};
        pointMax = {qx,qy};
        largeur = qx - px ;
        hauteur = qy-py ;
    }

    BoundingBox(const Vec2d& min, const Vec2d& max) {
        pointMin = min;
        pointMax = max;
        largeur = max[0] - min[0] ;
        hauteur = max[1] - min[1] ;
    }

    Vec2d getMin() const;
    void setMin(Vec2d& point);

    Vec2d getMax() const;
    void setMax(Vec2d& point);

    BoundingBox operator=(const BoundingBox& box); //copy
    BoundingBox operator+(const BoundingBox& box); //Union
    BoundingBox operator-(const BoundingBox& box); //Différence
    BoundingBox operator^(const BoundingBox& box); //Intersection
    bool isEmpty();
    Vec2d center();

    bool isInBox(const Vec2d& point);
    BoundingBox addPoint(const Vec2d& point);



};



#endif




