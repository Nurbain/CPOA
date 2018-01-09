#ifndef CSGDISK_H
#define CSGDISK_H

#include "csgPrimitive.h"
#include "../vectorMatrix/vector.h"

/**
 * @brief The csgDisk class, Classe de la primitive Graphique Disk
 */
class csgDisk : public csgPrimitive{
public:
    Vec2d centre;
    int rayon;

    /**
     * @brief csgDisk, constructeur
     * @param label, label "disk"
     * @param centre, point du centre du cercle
     * @param rayon, rayon du cercle
     */
    csgDisk(std::string label,Vec2d centre, int rayon);
    csgDisk(const csgDisk& copy);
    ~csgDisk(){}

    //Get/Set rayon,centre & Bounding Box
    int getRayon();
    void setRayon(int rayon);

    Vec2d getCentre();
    void setCentre(const Vec2d &centre);

    BoundingBox getBbox() const;
    void setBbox(BoundingBox &box);

    /**
     * @brief computeBoundingBox, calcule la bounding box du cercle
     * @return
     */
    BoundingBox computeBoundingBox();

    /**
     * @brief Intersect, regarde si le point est dans le cercle
     * @param v, point
     * @return
     */
    bool Intersect(Vec2d v);

    /**
     * @brief translation, translate le cercle suivant le vecteur donné
     * @param v
     */
    void translation(Vec2d v);

};


#endif
