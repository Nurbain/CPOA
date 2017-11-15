#include "image2Grey.h"
#include "Image2RGB.h"
#include "unistd.h"

int main()
{


    //------------------------
    //         TEST IMAGE
    //------------------------


    //--------------------------------------
    // Test Save et Load
    std::string Currentpath = get_current_dir_name();
    std::cout << get_current_dir_name()<<  std::endl;

    Currentpath +=  "/../../CPOA/image";

    Image2Grey test = Image2Grey(400,400);
    test.loadToPGM((Currentpath+"/test.pgm").c_str());

    test.saveToPGM((Currentpath+"/save.pgm").c_str());

    Image2Grey test2 = Image2Grey(400,400);
    test2.loadToPGM((Currentpath+"/save.pgm").c_str());
    for(int i = 0; i<test.getWidth();i++){
        for(int j = 0; j<test.getHeight();j++){
            assert(test(i,j) == test2(i,j));
        }
    }
    std::cout << "Test Load et Save  : PASSED" << std::endl;

    //---------------------------------------------------------
    // Test Tresholding

    int TresholdingVal = 170;
    Image2Grey test3 = test2.thresholding(TresholdingVal);

    for(int i = 0; i<test3.getWidth();i++){
        for(int j = 0; j<test3.getHeight();j++){
            assert(test3(i,j) == 0 || test3(i,j) == 255);
        }
    }

    test3.saveToPGM((Currentpath + "/thresholding.pgm").c_str());
    std::cout << "Test Tresholding : PASSED" << std::endl;

    //---------------------------------------------------------
    // Test Sampling
    Image2Grey test4 = test2.sampling();
    test4.saveToPGM((Currentpath + "/sampling.pgm").c_str());

    std::cout << "Test Sampling : PASSED" << std::endl;

    //---------------------------------------------------------
   // Test Smooting
    Image2Grey test5 = test2.smoothing(3);
    test5.saveToPGM((Currentpath + "/smoothing.pgm").c_str());

    std::cout << "Test Smoothing : PASSED" << std::endl;

    //---------------------------------------------------------
    // Test Cropping
    Image2Grey test6 = test2.cropping(175,85,390,300);
    test6.saveToPGM((Currentpath + "/cropping.pgm").c_str());

    std::cout << "Test Cropping : PASSED"  << std::endl;



    //---------------------------------------------------------
    // Test Sobel
    Image2D<Vec2d> testGradient = test2.GradientSobel5();
    Image2Grey test7 = test2.makeSobel(testGradient);
    test7.saveToPGM((Currentpath + "/sobel5.pgm").c_str());



    Image2D<Vec2d> testGradient2 = test2.GradientSobel3();
    Image2Grey test8 = test2.makeSobel(testGradient);
    test8.saveToPGM((Currentpath + "/sobel3.pgm").c_str());

    std::cout << "Test Sobel : PASSED"  << std::endl;

    //------------------------
    //         TEST IMAGE RGB
    //------------------------



    Image2RGB testRGB = Image2RGB(400,400);
    testRGB.loadToRGB((Currentpath + "/rgbTest.ppm").c_str());

     testRGB.saveToRGB((Currentpath + "/rgbTestSave.ppm").c_str());

     Image2RGB testRGB2 = Image2RGB(400,400);
     testRGB2.loadToRGB((Currentpath + "/rgbTestSave.ppm").c_str());

     for(int i = 0; i<testRGB.getWidth();i++){
         for(int j = 0; j<testRGB.getHeight();j++){
             assert(testRGB2(i,j)==testRGB(i,j));
         }
     }

    std::cout << "Test Save Load RGB : PASSED \n"<<  std::endl;


    //------------------------
    std::cout << "ALL TEST IMAGE2GREY PASSED"<<  std::endl;
    //------------------------
    std::cout << "ALL TEST IMAGE2RGB PASSED \n"<<  std::endl;

    return 0;
}
