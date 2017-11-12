/**
 * @author Nathan Urbain
 * @date 11/11/2017
 */

#include "image2Grey.h"

Image2Grey Image2Grey::seuillage(const int valeur){
    for(int i=0;i<this->getHeight();i++){
        for(int j=0;j<this->getWidth();j++){
            int index = i*j;
            if(this->getPixel(index)<valeur){
                this->setPixel(index,0);
            }
            else this->setPixel(index,255);
        }
    }
    return *this;
}
