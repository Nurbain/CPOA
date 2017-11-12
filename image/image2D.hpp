/**
 * @author Nathan URBAIN
 * @date 11/11/2017
 */

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "image2D.h"

Image2D& Image2D::operator=(const Image2D& img){
    this->height = img.getHeight();
    this->width = img.getWidth();

    for(int i=0;i<img.getWidth();i++){
        for(int j=0;j<img.getHeight();j++){
            this->data[i*j]=img.getPixel(i*j);
        }
    }
    return *this;
}

template<typename T>
void Image2D::switchImg(const Image2D& img1, const Image2D &img2){
    if(img1.getHeight() != img2.getHeight() || img1.getWidth() != img2.getWidth()){
        return;
    }

    for(int i=0;i<img1->getWidth();i++){
        for(int j=0 ;j<img1->getHeight();j++){
            int index = i*j;
            T tmp = img1.getPixel(index);
            img1.setPixel(index,img2.getPixel(index));
            img2.setPixel(index,tmp);
        }
    }
}

template<typename T>
T Image2D::getPixel(const int index){
    return this->data[i];
}

template<typename T>
void Image2D::setPixel(const int index, T pixel){
    this->data[index] = pixel;
}


int Image2D::getWidth(){
    return this->width;
}

int Image2D::getHeight(){
    return this->height;
}

void Image2D::setWidth(int const width){
    this->width = width;
}

void Image2D::setHeight(int const height){
    this->height = height;
}

//Cropping

#endif
