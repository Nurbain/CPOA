#ifndef CSGPOLYGON_H
#define CSGPOLYGON_H

#include "csgPrimitive.h"

/**
 * @brief The csgPolygon class, class Primitive Graphique de Polygone
 */
class csgPolygon : public csgPrimitive{
public:
    int nbface;
    Vec2d *tabSommet;

    csgPolygon(std::string label, int nbfaces);
    csgPolygon(const csgPolygon& copy);
    ~csgPolygon(){}


    //Get/Set Sommet,NbFace
    Vec2d getSommet(int indice);
    void addSommet(Vec2d som);

    int getNbFace();
    void setNbFace(int nbface);

    /**
     * @brief computeBoundingBox, calcule la boundingBox du polygone
     * @return
     */
    BoundingBox computeBoundingBox();

    /**
     * @brief Intersect, Interesction du point avec la primtive
     * @param v, point
     * @return
     */
    bool Intersect(Vec2d v);

    /**
     * @brief translation, translate la primitive
     * @param trans
     */
    void translation(Vec2d trans);

    /**
     * @brief rotation, rotation de la primitive
     * @param a, angle
     */
    void rotation(float a);

    /**
     * @brief getCoordBarycentre, récupère les coordonnées barycentriques du centre
     * @return
     */
    Vec2d getCoordBarycentre();

};

#endif
