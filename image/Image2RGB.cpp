/**
 * @author Nathan Urbain
 * @date 14/11/2017
 */


#include "Image2RGB.h"
#include <time.h>
#include <fstream>
#include <sstream>
#include <math.h>

// ---------------------------------------------------------------------
// Toute explicattions des différentes fonctions sont faites dans le .h
// Les tests d'image2RGB sont présent dans le fichier testMatrix.cpp
// ---------------------------------------------------------------------


int Image2RGB::saveToRGB(const char *path){
    std::ofstream fileOut;
    fileOut.open(path);

    //Put magical number
    fileOut << "P3" << std::endl;

    //Put dimension
    fileOut << width << " " << height << std::endl;

    //Put factor
    fileOut << "255" << std::endl;


    for (int i=0; i < width*height ; i++) {
        fileOut << (int)data[i][0] << "\n" ;
        fileOut << (int)data[i][1] << "\n" ;
        fileOut << (int)data[i][2] << "\n" ;
    }
    fileOut << std::endl;

    return 1;
}


int Image2RGB::loadToRGB(const char* path){
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
    // Verifie P3 number
    if (str != "P3") {
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
    data = new Vec3uc[width*height];


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

    unsigned int v1, v2, v11 , v12 , v22, v21;
    for (int i=0; i < height; i++) {
        for (int j=0; j < width; j++) {
            stream >> v1;
            v2 = (unsigned char)(f*v1);
            data[j + i*width][0] = v2;

            stream >> v11;
            v21 = (unsigned char)(f*v11);
            data[j + i*width][1] = v21;

            stream >> v12;
            v22 = (unsigned char)(f*v12);
            data[j + i*width][2] = v22;
        }
    }


    return 0;

}
