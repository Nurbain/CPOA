/**
 * @author Nathan URBAIN
 * @date 11/11/2017
 */

#ifndef IMAGE2D_HPP
#define IMAGE2D_HPP

#include "image2D.h"

// ---------------------------------------------------------------------
// Toute explicattions des différentes fonctions sont faites dans le .h
// Les tests d'image2D sont présent dans le fichier testMatrix.cpp
// ---------------------------------------------------------------------

template <typename T>
Image2D<T>::Image2D(const Image2D<T> &img){
    this->height=img.getHeight();
    this->width=img.getWidth();

    for(int i=0;i<this->width;i++){
        for(int j=0;j<this->height;j++){
            (*this)(i,j) = img(i,j);
        }
    }
}


template<typename T>
void Image2D<T>::swap_pixels(Image2D<T>& img){
    assert(img.getWidth() == this->width && img.getHeight()== this->height);
    std::swap(img.data,this->data);
}



template<typename T>
Image2D<T> Image2D<T>::cropping(const int Ax, const int Ay, const int Bx, const int By){
    int newWidth = Bx - Ax +1;
    int newHeight = By - Ay +1;
    Image2D<T> newImg = Image2D<T>(newWidth, newHeight);

    for(int i= Ax; i < Bx ; i++){
        for(int j=Ay; j<By ;j++){
            newImg(i,j) = (*this)(i,j);
        }
    }
    return newImg;
}



/// version pour les types (P)Array
/// le type P doit fournir [] -> type numeric, et size()
template <typename P>
auto convol3x3(Image2D<P>& image, const double* m) -> typename std::enable_if<!std::is_arithmetic<P>::value,void>::type
{

    int w = image.width();
    int h = image.height();

    Image2D<P> im(image.width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v;
            for(int iv=0; iv<v.size(); ++iv)
                v[i]=0;
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                {
                    auto& u = image(i+k,j+l);
                    for(int iv=0; iv<v.size(); ++iv)
                        v[i] += u[i] * (*p);
                    p++;
                }
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}

/// version pour les types (P) numériques
template <typename P>
auto convol3x3(Image2D<P>& image, const double* m) -> typename std::enable_if<std::is_arithmetic<P>::value,void>::type
{
    int w = image.width();
    int h = image.height();

    Image2D<P> im(image.width(),image.height());

    for(int j=1;j<h-1;j++)
        for(int i=1;i<w-1;i++)
        {
            P v(0);
            const double* p = m;
            for(int l=-1;l<2;l++)
                for(int k=-1;k<2;k++)
                    v += image(i+k,j+l)*(*p++);
            im(i,j) = v;
        }

    for(int j=0;j<h;j++)
    {
        im(0,j) = image(0,j);
        im(w-1,j) = image(w-1,j);
    }

    for(int i=0;i<w;i++)
    {
        im(i,0) = image(i,0);
        im(i,h-1) = image(i,h-1);
    }

    image.swap_pixels(im);
}

#endif
