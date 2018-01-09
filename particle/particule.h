#ifndef PARTICULE_H
#define PARTICULE_H

#include "vector.h"

#define GRAVITY 9.81/100 //Comme avec le prof on divise par 50 l'echelle

/**
 * @brief The Particule class, classe particule
 */
class Particule {
protected:
    //Position et vitesse courante du point
    Vec2d pos_courant;
    double vit_courant;

    //Position et vitesse future du point
    Vec2d pos_future;
    double vit_future;

    //Date actuel du point
    int dateActuel;

public :
    Particule();

    //Get et Set des positions,vitesse et Date
    Vec2d getPos_courant() const;
    void setPos_courant(const Vec2d &pos_courant);

    double getVit_courant() const;
    void setVit_courant(double vit_courant);

    Vec2d getPos_future() const;
    void setPos_future(const Vec2d &pos_future);


    double getVit_future() const;
    void setVit_future(double vit_future);

    int getDateActuel() const;
    void setDateActuel(int dateActuel);

    /**
     * @brief computeVitFuture, calcule la vitesse future du point
     */
    void computeVitFuture();

    /**
     * @brief computePosFuture, calcule la position future du point
     */
    void computePosFuture();

    /**
     * @brief changePosition, echange le point courant avec le futur
     */
    void changePosition();
};

#endif // PARTICULE_H
