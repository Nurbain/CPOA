/**
 * @author Nathan URBAIN
 * @date 11/11/2017
 */

#ifndef IMAGE_H
#define IMAGE_H


template <typename T>
class Image2D{
    protected :
        int height;
        int width;
        T* data;


    public :
        inline Image2D(int height, int width){
            this->height=height;
            this->width=width;
            this->data = T[height*width];
        }

        ~Image2D();

        Image2D& operator=(const Image2D& img);

        void switchImg(const Image2D& img1,const Image2D& img2);

        T getPixel(const int index);
        void setPixel(const int index, T pixel);

        int getWidth();
        void setWidth(int const width);

        int getHeight();
        void setHeight(int const height);

        //Cropping

};

#endif
