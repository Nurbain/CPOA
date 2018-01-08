#include "CsgPolygon.h"

csgPolygon::csgPolygon(std::string label, int nbfaces) : csgPrimitive(label) {

    nbface = 0;
    tabSommet = new Vec2d[100];

    for (int i = 0; i < nbfaces; i++) {
        double x = 20 * cos(2*M_PI*i/nbface);
        double y = 20 * sin(2*M_PI*i/nbface);
        x = x + 50;
        y = y + 50;
        Vec2d pts= {x,y};
        this->addSommet(pts);
    }

    box = this->computeBoundingBox();
}


csgPolygon::csgPolygon(const csgPolygon& copy) : csgPrimitive(copy) {
    nbface = copy.nbface;
    tabSommet = copy.tabSommet;
}

Vec2d csgPolygon::getSommet(int indice) {
    return tabSommet[indice];
}

void csgPolygon::addSommet(Vec2d som) {
    tabSommet[nbface] = som;
    nbface++;
}

int csgPolygon::getNbFace() {
    return nbface;
}


void csgPolygon::setNbFace(int nbface) {
    this->nbface = nbface;
}


BoundingBox csgPolygon::computeBoundingBox() {
    Vec2d max;
    Vec2d min;
    BoundingBox res;

    max[0] = tabSommet[0][0];
    max[1] = tabSommet[0][1];
    min[0] = tabSommet[0][0];
    min[1] = tabSommet[0][1];

    for(int i = 1; i< nbface; i++) {
        if(max[0] < tabSommet[i][0]) {
            max[0] = tabSommet[i][0];
        }
        if(max[1] > tabSommet[i][1]) {
            max[1] = tabSommet[i][1];
        }
        if(min[0] > tabSommet[i][0]) {
            min[0] = tabSommet[i][0];
        }
        if (min[1] < tabSommet[i][1]) {
            min[1] = tabSommet[i][1];
        }
    }

    res.setMin(min);
    res.setMax(max);

    return res;
}


bool csgPolygon::Intersect(Vec2d v) {

    /*
    for(int i=0;i< nbface;i++)
    {
        Vec2d A = tabSommet[i];
        Vec2d B;
        // si queue
        if (i==nbface-1){
            B = tabSommet[0];
        }
        else{
            B = tabSommet[i+1];
        }

        Vec2d D,T;
        D[0] = B[0] - A[0];
        D[1] = B[1] - A[1];
        T[0] = v[0] - A[0];
        T[1] = v[1] - A[1];
        float d = D[0]*T[1] - D[1]*T[0];
        if (d<0)
            return false;
    }
    return true;*/
}


void csgPolygon::translation(Vec2d trans) {
    Vec3d newVec;

    for (int i = 0; i < nbface; i++) {
        mat_transfo.translation(trans[0], trans[1]);
        Vec3d vec = {tabSommet[i][0],tabSommet[i][1],1.0};
        newVec = mat_transfo*vec;
        tabSommet[i][0] = newVec[0]/newVec[2];
        tabSommet[i][1] = newVec[1]/newVec[2];

    }
    box = this->computeBoundingBox();

}


Vec2d csgPolygon::getCoordBarycentre() {
    Vec2d Coordbarycentre;
    Coordbarycentre[0] = 0;
    Coordbarycentre[1] = 0;

    for (int i = 0; i < nbface; i++) {
        Coordbarycentre[0] += tabSommet[i][0];
        Coordbarycentre[1] += tabSommet[i][1];
    }

    Coordbarycentre[0] = Coordbarycentre[0]/nbface;
    Coordbarycentre[1] = Coordbarycentre[1]/nbface;

    return Coordbarycentre;
}


void csgPolygon::rotation(float angle) {
    Vec3d newVec;
    Vec2d translatInverse = this->getCoordBarycentre();

    for (int i = 0; i < nbface; i++) {

        mat_transfo.translation(-translatInverse[0], -translatInverse[1]);
        Vec3d vec = {tabSommet[i][0],tabSommet[i][1],1};
        newVec = mat_transfo*vec;

        mat_transfo.setRotation(angle);
        newVec = mat_transfo*newVec;

        mat_transfo.translation(translatInverse[0], translatInverse[1]);
        newVec = mat_transfo*newVec;

        tabSommet[i][0] = newVec[0]/newVec[2];
        tabSommet[i][1] = newVec[1]/newVec[2];

    }

    box = this->computeBoundingBox();

}

