/**
 * @author Nathan URBAIN
 * @date 11/11/2017
 */

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <assert.h>

/**
 * @class Image2D
 * @brief Template Class for images
 * @property {int}   height of the image
 * @property {int}   width of the image
 * @property {T*]    pixel value
 */
template <typename T>
class Image2D{
    protected :
        int height;
        int width;
        T* data;


    public :
        /**
         * @brief Image2D, constructor
         * @param height
         * @param width
         */
        inline Image2D(int height, int width){
            this->height=height;
            this->width=width;
            this->data = new T[height*width];
        }

        /**
         * @brief Image2D, constructor by giving an image
         * @param img, img to copy
         */
        Image2D(const Image2D<T>& img);

        /**
         * @brief destructor
         */
        ~Image2D(){
            delete[] data;
        }

        /**
         * @brief operator (), accessor operator
         * @param i line
         * @param j colomne
         * @return  pixel value
         */
        T& operator ()(int i,int j) { return data[i+j*width];}
        const T& operator ()(int i,int j) const {return data[i+j*width];}

        /**
         * @brief getWidth
         * @return current width
         */
        int getWidth() const {return width;}

        /**
         * @brief getHeight
         * @return current height
         */
        int getHeight() const {return height;}

        /**
         * @brief getData
         * @return current pixel tab
         */
        T* getData() const {return data;}

        /**
         * @brief swap_pixels, swap all pixel from an image to an other
         * @param img, image to swap with
         */
        void swap_pixels(Image2D& img);

        /**
         * @brief cropping, cropp the current image between 2 given points
         * @param Ax, coord. x of the first point
         * @param Ay, coord. y of the first point
         * @param Bx, coord. x of the second point
         * @param By, coord. y of the second point
         * @return new Image2D
         */
        Image2D cropping(const int Ax,const int Ay,const int Bx,const int By);

        /**
         * @brief convol3x3, make convolution
         * @param m
         */
        void convol3x3(const double* m){
            Image2D<T> img = Image2D<T>(this->getWidth(),this->getHeight());

            for(int j=1;j<this->getHeight()-1;j++)
                for(int i=1;i<this->getWidth()-1;i++)
                {
                    double v = 0;
                    const double* p = m;
                    for(int l=-1;l<2;l++)
                        for(int k=-1;k<2;k++)
                            v += (*this)(i+k,j+l)*(*p++);
                    img(i,j) = T(v);
                }

            // copie du bord
            for(int j=0;j<this->getHeight();j++)
            {
                img(0,j) = (*this)(0,j);
                img(this->getWidth()-1,j) = (*this)(this->getWidth()-1,j);
            }

            for(int i=0;i<this->getWidth();i++)
            {
                img(i,0) = (*this)(i,0);
                img(i,this->getHeight()-1) = (*this)(i,this->getHeight()-1);
            }

            this->swap_pixels(img);
        }

};


#include "image2D.hpp"

#endif
