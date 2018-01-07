#include "particule.h"
#include <math.h>


Particule::Particule(){
    dateActuel = 0;
    vit_courant = 1;
}

Vec2d Particule::getPos_courant() const
{
    return pos_courant;
}

void Particule::setPos_courant(const Vec2d &pos_courant)
{
    this->pos_courant = pos_courant;
}

double Particule::getVit_courant() const
{
    return vit_courant;
}

void Particule::setVit_courant(double vit_courant)
{
    this->vit_courant = vit_courant;
}


Vec2d Particule::getPos_future() const
{
    return pos_future;
}

void Particule::setPos_future(const Vec2d &pos_future)
{
    this->pos_future = pos_future;
}


double Particule::getVit_future() const
{
    return vit_future;
}

void Particule::setVit_future(double vit_future)
{
    this->vit_future = vit_future;
}

int Particule::getDateActuel() const
{
    return dateActuel;
}

void Particule::setDateActuel(int dateActuel)
{
    this->dateActuel = dateActuel;
}

void Particule::computeVitFuture() {
    int newDate = dateActuel/50;
    vit_future = vit_courant + GRAVITY * newDate;

}

void Particule::computePosFuture() {
    pos_future[0] = pos_courant[0];
    int newDate = dateActuel/50;
    pos_future[1] = pos_courant[1] + vit_courant * newDate + (1/2) * GRAVITY * pow(newDate,2);
}

void Particule::changePosition() {
    pos_courant = pos_future;
    vit_future = vit_courant;
}
