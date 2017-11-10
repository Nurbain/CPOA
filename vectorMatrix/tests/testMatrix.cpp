#include <iostream>
#include "matrix33d.h"

int main()
{
    Array<double,3> a1 = Array<double,3>();
    assert(a1[0] == 0);
    assert(a1[1] == 0);
    assert(a1[2] == 0);
    std::cout << "Test contructor array empty : PASSED" << std::endl;

    //------------------------
    //Test Constructor
    Matrix33d m1 = Matrix33d();
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            assert(m1[i][j] == 0);
        }
    }
    std::cout << "Test empty constructor : PASSED"<<  std::endl;

    int x = 0;
    Matrix33d m2 = {0,1,2,3,4,5,6,7,8};
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            assert(m2[i][j]==x);
            x++;
        }
    }
    std::cout << "Test list constructor : PASSED"<<  std::endl;

    //------------------------
    //Test Copy
    Matrix33d m5 = m2;
    for(int i=0;i<DIM;i++){
        for(int j=0;j<DIM;j++){
            assert(m5[i][j]==m2[i][j]);
            x++;
        }
    }
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
    //Test Multpilication vecteur
    Matrix33d m6 = {1,1,1,2,2,2,3,3,3};
    Vec3d v1 = {1,2,3};
    v1 = m6*v1;
    assert(v1[0] == 6);
    assert(v1[1] == 12);
    assert(v1[2] == 18);
    std::cout << "Test Multpilication vecteur : PASSED" <<  std::endl;


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
    //Test Display
    Matrix33d m = {1,45,3,0,4,8,9,7,42};
    std::cout << "Test Display : \n" <<m <<  std::endl;


/*

	std::cout << "translate(3.5f,2.4f) "<<  std::endl;
	m1.translate(3.5f,2.4f);
	std::cout << m1 <<  std::endl;

	x = 0.0;
	y = 0.0;
	m1.applyTransformation(x,y);
	std::cout << "0,0 => "<< x << "," << y << std::endl;

	m1.rotate(0.4);
	Matrix33d m2 = m1.inverse();

	std::cout << m1 << std::endl<<"*"<< std::endl<<m2<< "=" << std::endl<< m1*m2 << std::endl;
    */

	return 0;

}
