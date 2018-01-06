/**
 * @author Nathan Urbain
 * @date 11/11/2017
 */

#include "image2Grey.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <math.h>
#include "../vectorMatrix/vector.h"

// ---------------------------------------------------------------------
// Toute explicattions des différentes fonctions sont faites dans le .h
// Les tests d'image2Grey sont présent dans le fichier testMatrix.cpp
// ---------------------------------------------------------------------

int Image2Grey::loadToPGM(const char* path){


    std::ifstream is;
    is.open(path);

    // file size
    is.seekg(0, is.end);
    int size = is.tellg();
    is.seekg(0, is.beg);

    // tmp buffer to stock on the futur stream
    char* buffer = new char[size];
    is.read(buffer, size);
    is.close();

    std::stringstream stream;
    stream.str(buffer);

    //delete tmp buffer
    delete[] buffer;

    // variable for the getline
    std::string str;


    std::getline(stream, str);
    // Verifie P2 number
    if (str != "P2") {
        std::cerr << "Bad magic number : " << str << std::endl;
        return -1;
    }


    std::getline(stream, str);
    // Skip all comments
    while (str[0] == '#') {
        std::getline(stream, str);
    }

    //Get dimension
    std::stringstream line;
    line.str(str);
    line >> width;
    line >> height;

    // Delete to init the new data
    if (data != nullptr) {
        delete[] data, data = nullptr;
    }
    data = new unsigned char[width*height];


    std::getline(stream, str);
    // Skip all comments
    while (str[0] == '#') {
        std::getline(stream, str);
    }

    //Put a the beginning
    line.str(str);
    line.seekg(0, line.beg);

    // Max value = white color
    int max;
    line >> max;
    // factor for the product
    float f = 255/(float)max;

    // Skip all comments
    while (stream.str()[stream.tellg()] == '#') {
        std::getline(stream, str);
    }

    unsigned int v1, v2;
    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            stream >> v1;
            v2 = (unsigned char)(f*v1);
            data[j + i*width] = v2;
        }
    }


    return 0;

}

int Image2Grey::saveToPGM(const char* path){

    std::ofstream fileOut;
    fileOut.open(path);

    //Put magical number
    fileOut << "P2" << std::endl;

    //Put dimension
    fileOut << width << " " << height << std::endl;

    //Put factor
    fileOut << "255" << std::endl;


    for (int i=0; i < width*height ; i++) {
        fileOut << (int)data[i] << " ";
    }
    fileOut << std::endl;

    return 1;
}


Image2Grey Image2Grey::thresholding(int tresh){
    Image2Grey newImg = Image2Grey(height,width);

    if(tresh > 255)
        tresh = 255;
    if(tresh < 0)
        tresh = 0;

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if((*this)(j,i)<(unsigned char)tresh){
                newImg(j,i)=(unsigned char)0;
            }else{
                newImg(j,i)=(unsigned char)255;
            }
       }
    }
    return newImg;
}


Image2Grey Image2Grey::smoothing(int nbr)
{
    int newWidth = width;
    int newHeight = height;


    Image2Grey smoothed = Image2Grey(newHeight, newWidth);


    if(nbr > 10 || nbr > width || nbr > height){
        return smoothed;
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int moyenne = 0;

            // max to verifie if we don't go outside the image
            for(int x = std::max(0, i - nbr); x < std::min(i + nbr, height); x++){
                for(int y = std::max(0, j - nbr); y < std::min(j + nbr, width); y++){
                    moyenne += (*this)(y, x);
                }
            }

            moyenne /= pow(2*nbr + 1, 2);

            smoothed(j, i) = (unsigned char)moyenne;
        }
    }

    return smoothed;
}


Image2Grey Image2Grey::sampling(){
    int newWidth = width/2;
        int newHeight = height/2;


        if(newWidth % 2 != 0){
            newWidth--;
        }
        if(newHeight % 2 != 0){
            newHeight--;
        }


        Image2Grey newImage = Image2Grey(newHeight,newWidth);

        for(int j=0;j<height-2;j=j+2){
            for(int i=0;i<width-2;i=i+2){
                newImage(i/2,j/2) = (*this)(i,j);
            }
        }
    return newImage;
}


Image2Grey Image2Grey::cropping(const int Ax, const int Ay, const int Bx, const int By){
    int newWidth = Bx - Ax +1;
    int newHeight = By - Ay +1;

    Image2Grey newImg = Image2Grey(newHeight, newWidth);

    for(int i= Ax; i < Bx ; i++){
        for(int j=Ay; j<By ;j++){
            newImg(i-Ax,j-Ay) = (*this)(i,j);
        }
    }

    return newImg;
}


Image2D<Vec2d> Image2Grey::GradientSobel5()
{
    Image2D<Vec2d> newImg = Image2D<Vec2d>(height, width);

    const int Sobel5x[25]={1,2,0,-2,-1,
                          4,8,0,-8,-4,
                          6,12,0,-12,-6,
                          4,8,0,-8,-4,
                          1,2,0,-2,-1};

    const int Sobel5y[25]={1, 4, 6, 4, 1,
                          2, 8, 12, 8, 2,
                          0, 0, 0, 0, 0,
                          -2,-8,-12,-8,-2,
                          -1,-4,-6,-4,-1};


        for(int j = 2; j < width -2 ; j++)
        {
            for(int i = 2; i < height -2 ; i++)
            {
            // X convolution computing
            int X_convo = 0;
            int indexX_convo = 0;

            for(int x = j - 2; x < j + 2; x++)
            {
                for(int y = i - 2; y < i + 2; y++)
                {
                    //Calcule le gradient x
                    X_convo += (*this)(x, y) * Sobel5x[indexX_convo];
                    indexX_convo++;
                }
            }

            // Y convolution computing
            int Y_convo = 0;
            int indexY_convo = 0;

            for(int x = j - 2; x < j + 2; x++)
            {
                for(int y = i - 2; y < i + 2; y++)
                {
                    //Calcule le gradient y
                    Y_convo += (*this)(x, y) * Sobel5y[indexY_convo];
                    indexY_convo++;
                }
            }

           newImg(j, i)[0] = X_convo/25;
           newImg(j, i)[1] = Y_convo/25;
        }
    }

    return newImg;
}

Image2D<Vec2d> Image2Grey::GradientSobel3(){
    Image2D<Vec2d> newImg = Image2D<Vec2d>(height, width);

    const double Sobel3x[9]={-1, 0, 1,
                         -2, 0 ,2,
                         -1, 0, 1};

    const double Sobel3y[9]={-1, -2, -1,
                         0, 0, 0,
                         1, 2, 1};


        for(int j = 1; j < width -1 ; j++)
        {
            for(int i = 1; i < height -1 ; i++)
            {
            // X convolution computing
            double X_convo = 0;
            int indexX_convo = 8;

            for(int x = j - 1; x < j + 1; x++)
            {
                for(int y = i - 1; y < i + 1; y++)
                {
                    //Calcule le gradient x
                    X_convo += (*this)(x, y) * Sobel3x[indexX_convo];
                    indexX_convo--;
                }
            }

            // Y convolution computing
            double Y_convo = 0;
            int indexY_convo = 8;

            for(int x = j - 1; x < j + 1; x++)
            {
                for(int y = i - 1; y < i + 1; y++)
                {
                    //Calcule le gradient Y
                    Y_convo += (*this)(x, y) * Sobel3y[indexY_convo];
                    indexY_convo--;
                }
            }

           newImg(j, i)[0] = X_convo;
           newImg(j, i)[1] = Y_convo;
        }
    }

    return newImg;
}

Image2Grey Image2Grey::makeSobel(const Image2D<Vec2d>&  gradientSobel){

    Image2Grey sobelImg = Image2Grey(height,width);

    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            int value = sqrt( gradientSobel(j,i)[0]*gradientSobel(j,i)[0] + gradientSobel(j,i)[1]*gradientSobel(j,i)[1] );
            if(value < 0)
                value = 0;
            if(value > 255)
                value = 255;

            sobelImg(j,i) = (unsigned char)value;
        }
    }

    return sobelImg;
}
