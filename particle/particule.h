#ifndef PARTICULE_H
#define PARTICULE_H

#include "vector.h"

#define GRAVITY 9.81/100 //Comme avec le prof on divise par 50 l'echelle

class Particule {
protected:
    Vec2d pos_courant;
    double vit_courant;

    Vec2d pos_future;
    double vit_future;

    int dateActuel;

public :
    Particule();

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

    void computeVitFuture();
    void computePosFuture();
    void changePosition();
};

#endif // PARTICULE_H
