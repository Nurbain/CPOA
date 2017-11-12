/**
 * @author Nathan Urbain
 * @date 11/11/2017
 */

#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include "image2D.h"

class Image2Grey : public Image2D<unsigned char>{

public:

    //Chargement
    //Sauvgarde
    //Sous echantillonnage
    //lissage

    Image2Grey seuillage(const int valeur);
};

#endif
