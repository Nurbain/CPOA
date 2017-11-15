#include <iostream>
#include "matrix33d.h"
#include "../image/image2D.h"
#include "../image/image2Grey.h"
#include "../image/Image2RGB.h"
#include "unistd.h"

int main()
{
    //---------------------------
    //         TEST MATRIX33D
    //---------------------------

    //------------------------

    //Test Constructor
    Matrix33d m1 = Matrix33d();
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            assert(m1[i][j] == 0);
        }
    }
    std::cout << "Test empty constructor : PASSED"<<  std::endl;

    int incrementation = 0;
    Matrix33d m2 = {0,1,2,3,4,5,6,7,8};
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            assert(m2[i][j]==incrementation);
            incrementation++;
        }
    }
    std::cout << "Test list constructor : PASSED"<<  std::endl;

    //------------------------
    //Test Copy
    Matrix33d mcopy = m2;
    assert(mcopy==m2);
    std::cout << "Test copy : PASSED"<<  std::endl;


    //------------------------
    //Test Identity
    Matrix33d m3 = Matrix33d::identity();
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            if(i==j){
                assert(m3[i][j] == 1);
            }
            else{
                assert(m3[i][j] == 0);
            }
        }
    }
    std::cout << "Test identity : PASSED"<<  std::endl;


    //------------------------
    //Test Inverse
    Matrix33d m4 ={1,2,3,0,1,4,5,6,0};
    m4 = m4.inverse();
    assert(m4[0][0] == -24);
    assert(m4[0][1] == 18);
    assert(m4[0][2] == 5);
    assert(m4[1][0] == 20);
    assert(m4[1][1] == -15);
    assert(m4[1][2] == -4);
    assert(m4[2][0] == -5);
    assert(m4[2][1] == 4);
    assert(m4[2][2] == 1);
    std::cout << "Test inverse : PASSED"<<  std::endl;


    //------------------------
    //Test static translation
    Matrix33d m7 = Matrix33d::translation(2,4);
    for(int i = 0; i<DIM; i++){
        for(int j=0 ;j<DIM ;j++){
            if(i==j)
                assert(m7[i][j]==1);
            else if(i==0 && j==2)
                assert(m7[i][j]==2);
            else if(i==1 && j==2)
                assert(m7[i][j]==4);
            else
                assert(m7[i][j]==0);
        }
    }
    std::cout << "Test Matrice translation : PASSED" <<  std::endl;

    //------------------------
    //Test static rotation
    Matrix33d m8 = Matrix33d::rotation(M_PI);
    for(int i = 0; i<DIM; i++){
        for(int j=0 ;j<DIM ;j++){
            if(i==j && i!=2)
                assert(m8[i][j]==-1);
            else if(i==j)
                assert(m8[i][j]==1);
            else if(i==0 && j==1)
                assert(m8[i][j]-sin(M_PI)<= 0.0000001 && m8[i][j]-sin(M_PI)>= -0.0000001 );
            else if(i==1 && j==0)
                assert(m8[i][j]-sin(M_PI)<= 0.0000001 && m8[i][j]-sin(M_PI)>= -0.0000001 );
            else
                assert(m8[i][j]==0);
        }
    }
    std::cout << "Test Matrice rotation : PASSED" <<  std::endl;

    //------------------------
    //Test static scaling
    Matrix33d m9 = Matrix33d::scale(4,4);
    for(int i = 0; i<DIM; i++){
        for(int j=0 ;j<DIM ;j++){
            if(i==j && i != 2)
                assert(m9[i][j]==4);
            else if(i==j)
                assert(m9[i][j]==1);
            else
                assert(m9[i][j]==0);
        }
    }
    std::cout << "Test Matrice homothétie : PASSED" <<  std::endl;

    //------------------------
    //Test composition matrice
    Matrix33d m10 = {1,1,1,2,2,2,3,3,3};
    Matrix33d m11 = {1,4,5,3,5,6,1,2,3};
    Matrix33d m12 = m10*m11;
    assert(m12[0][0]==5);
    assert(m12[0][1]==11);
    assert(m12[0][2]==14);
    assert(m12[1][0]==10);
    assert(m12[1][1]==22);
    assert(m12[1][2]==28);
    assert(m12[2][0]==15);
    assert(m12[2][1]==33);
    assert(m12[2][2]==42);
    std::cout << "Test composition matrice : PASSED" <<  std::endl;

    //------------------------
    //Test Multpilication vecteur
    Matrix33d m6 = {1,1,1,2,2,2,3,3,3};
    Vec3d v1 = {1,2,3};
    v1 = m6*v1;
    assert(v1[0] == 6);
    assert(v1[1] == 12);
    assert(v1[2] == 18);
    std::cout << "Test Multpilication vecteur : PASSED" <<  std::endl;

    //Test equality operator
    Matrix33d m18 = {7,8,9,4,5,6,1,2,3};
    Matrix33d m19 = m18;
    assert(m18==m19);
    m19[0][0]=666;
    assert(!(m18==m19));
    std::cout << "Test equality operator : PASSED" <<  std::endl;

    //------------------------
    //Test application transformation vec2d
    Matrix33d m13 = {4,0,0,0,4,0,0,0,1};
    Vec2d v2 = {2,2};
    Vec3d v3 = m13 * v2;
    assert(v3[0]==8);
    assert(v3[1]==8);
    assert(v3[2]==1);
    std::cout << "Test Application transformation : PASSED" <<  std::endl;

    //------------------------
    //Test set & apply rotation
    Matrix33d m14 = Matrix33d();
    m14.setRotation(M_PI);
    for(int i = 0; i<DIM; i++){
        for(int j=0 ;j<DIM ;j++){
            if(i==j && i!=2)
                assert(m14[i][j]==-1);
            else if(i==j)
                assert(m14[i][j]==1);
            else if(i==0 && j==1)
                assert(m14[i][j]-sin(M_PI)<= 0.0000001 && m14[i][j]-sin(M_PI)>= -0.0000001 );
            else if(i==1 && j==0)
                assert(m14[i][j]-sin(M_PI)<= 0.0000001 && m14[i][j]-sin(M_PI)>= -0.0000001 );
            else
                assert(m14[i][j]==0);
        }
    }

    Matrix33d m15 = Matrix33d::identity();
    m15.applyRotation(M_PI);
    assert(m15==m14);

    std::cout << "Test Set & apply rotation : PASSED" <<  std::endl;

    //------------------------
    //Test set & apply scaling
    Matrix33d m16 = Matrix33d();
    m16.setScale(2,2);
    for(int i = 0; i<DIM; i++){
        for(int j=0 ;j<DIM ;j++){
            if(i==j && i != 2)
                assert(m16[i][j]==2);
            else if(i==j)
                assert(m16[i][j]==1);
            else
                assert(m16[i][j]==0);
        }
    }

     Matrix33d m17 = Matrix33d::identity();
     m17.applyScale(2,2);
     assert(m17==m16);

    std::cout << "Test Set & apply scaling : PASSED" <<  std::endl;

    //------------------------
    //Test Display
    Matrix33d m = {1,45,3,0,4,8,9,7,42};
    std::cout << "Test Display : \n" <<m <<  std::endl;

    //------------------------
    std::cout << "\n ALL TEST MATRIX PASSED \n"<<  std::endl;



    //------------------------
    //         TEST IMAGE
    //------------------------


    //--------------------------------------
    // Test Save et Load
    std::string Currentpath = get_current_dir_name();
    std::cout << get_current_dir_name()<<  std::endl;

    Currentpath +=  "/../../../CPOA/image";

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


    Image2D<Vec2d> testGradient = test2.GradientSobel();
    Image2Grey test7 = test2.makeSobel(testGradient);
    test7.saveToPGM((Currentpath + "/sobel.pgm").c_str());

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



    std::cout << "\nALL TEST MATRIX PASSED"<<  std::endl;
    //------------------------
    std::cout << "ALL TEST IMAGE2GREY PASSED"<<  std::endl;
    //------------------------
    std::cout << "ALL TEST IMAGE2RGB PASSED \n"<<  std::endl;



    return 0;

}
