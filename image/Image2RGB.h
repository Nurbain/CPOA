/**
 * @author Nathan Urbain
 * @date 14/11/2017
 */

#ifndef IMAGE2RGB_H
#define IMAGE2RGB_H


#include "image2D.h"
#include "../vectorMatrix/vector.h"

/**
 * @class Image2RGB
 * @brief Class who define RGB images
 */
class Image2RGB : public Image2D<Vec3uc>{

public:

    /**
     * @brief Image2RGB, constructor from Image2D
     * @param height
     * @param width
     */
    Image2RGB(int height , int width): Image2D<Vec3uc>(height,width){}

    /**
     * @brief saveToPGM, save a the current image on the format PGM
     * @param path, absolute path of image's location  to save
     * @return true if done
     */
    int saveToRGB(const char *path);

    /**
     * @brief loadToPGM, load an image given by the path
     * @param path, absolute path of image's location
     * @return true if done
     */
    int loadToRGB(const char* path);
};

#endif
