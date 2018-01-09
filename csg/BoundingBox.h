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

    Vec2d pointMin; //p1
    Vec2d pointMax; //p2
    float largeur;
    float hauteur;


public:

    //Constructeur vide
    BoundingBox();


    /**
     * @brief BoundingBox, constructeur par 4 points
     * @param px, x bottom left
     * @param py, y bottom left
     * @param qx, x right top
     * @param qy, y right top
     */
    BoundingBox(const float px, const float py, const float qx, const float qy) {
        pointMin = {px,py};
        pointMax = {qx,qy};
        largeur = qx - px ;
        hauteur = qy-py ;
    }

    /**
     * @brief BoundingBox, constructueur par 2 vecteurs s
     * @param min, bottom left
     * @param max, right top
     */
    BoundingBox(const Vec2d& min, const Vec2d& max) {
        pointMin = min;
        pointMax = max;
        largeur = max[0] - min[0] ;
        hauteur = max[1] - min[1] ;
    }

    //Get/Set des 2 Vecteurs Min & Max
    Vec2d getMin() const;
    void setMin(Vec2d& point);

    Vec2d getMax() const;
    void setMax(Vec2d& point);

    //Overload Operateur
    BoundingBox operator=(const BoundingBox& box); //copy
    BoundingBox operator+(const BoundingBox& box); //Union
    BoundingBox operator-(const BoundingBox& box); //Différence
    BoundingBox operator^(const BoundingBox& box); //Intersection

    /**
     * @brief isEmpty, Verifie si une bounding box est vide
     * @return true si les points min & max sont egaux
     */
    bool isEmpty();

    /**
     * @brief center, donne le centre de la bounding box
     * @return Vec2d
     */
    Vec2d center();

    /**
     * @brief isInBox, Regarde si un point est dans la bounding box
     * @param point
     * @return  boolean
     */
    bool isInBox(const Vec2d& point);

    /**
     * @brief addPoint, Agrandir la bounding box pour englober le point
     * @param point
     * @return
     */
    BoundingBox addPoint(const Vec2d& point);

};



#endif




