/**
 * @author Nathan Urbain
 * @date 11/11/2017
 */

#ifndef IMAGE2GREY_H
#define IMAGE2GREY_H

#include "image2D.h"
#include "../vectorMatrix/vector.h"

/**
 * @class Image2Grey
 * @brief Class who define PGM images
 */
class Image2Grey : public Image2D<unsigned char>{

public:

    /**
     * @brief Image2Grey, constructor from Image2D
     * @param height
     * @param width
     */
    Image2Grey(int height , int width): Image2D<unsigned char>(height,width){}

    /**
     * @brief saveToPGM, save a the current image on the format PGM
     * @param path, absolute path of image's location  to save
     * @return true if done
     */
    int saveToPGM(const std::string &path);

    /**
     * @brief loadToPGM, load an image given by the path
     * @param path, absolute path of image's location
     * @return true if done
     */
    int loadToPGM(const std::string &path);

    /**
     * @brief thresholding, make a treshholdin on the current image
     * @param tresh, value to compare pixel with
     * @return new Image2Grey
     */
    Image2Grey thresholding(int tresh);

    /**
     * @brief sampling, sampling by 2 the current image
     * @return new Image2Grey
     */
    Image2Grey sampling();

    /**
     * @brief smoothing, compute a smooth on the current image
     * @param smooth, number of pixel to look for the smoothing
     * @return new Image2Grey
     */
    Image2Grey smoothing(int nbr);

    /**
     * @brief cropping, cropp the current image between 2 given points
     * @param Ax, coord. x of the first point
     * @param Ay, coord. y of the first point
     * @param Bx, coord. x of the second point
     * @param By, coord. y of the second point
     * @return new Image2Grey
     */
    Image2Grey cropping(const int Ax, const int Ay, const int Bx, const int By);

    /**
     * @brief GradientSobel5, compute a sobel image who look 24 pixel around
     * @return new sobel image
     */
    Image2D<Vec2d> GradientSobel5();


    /**
     * @brief GradientSobel3, compute a sobel image who look 8 pixel around
     * @return new sobel image
     */
    Image2D<Vec2d> GradientSobel3();

    /**
     * @brief makeSobel
     * @param gradientSobel
     * @return
     */
    Image2Grey makeSobel(const Image2D<Vec2d>&  gradientSobel);
};

#endif
