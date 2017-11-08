#include <iostream>
#include "vector.h"

int main()
{
    //------------------------
    //Test Constructor
    Vec3d v2 = Vec3d();
    assert(v2[0] == 0);
    assert(v2[1] == 0);
    assert(v2[2] == 0);
    std::cout << "Constructeur par Default : PASSED" << std::endl;

    Vec3d v1 = {1,2,3};
    assert(v1[0] == 1);
    assert(v1[1] == 2);
    assert(v1[2] == 3);
    std::cout << "Constructeur par Liste : PASSED" << std::endl;

    //------------------------
    //Test Copy
    v2 = v1;
    assert(v2[0] == 1);
    assert(v2[1] == 2);
    assert(v2[2] == 3);
    std::cout << "Operator = : PASSED" << std::endl;

    //------------------------
    //Test equality
    bool result = v2==v1;
    Vec3d v2Bis = Vec3d();
    bool resultBis = v2Bis==v1;
    assert(result == 1);
    assert(resultBis == 0);
    std::cout << "Operator == : PASSED" << std::endl;

    //------------------------
    //Test Sum
    Vec3d v3 = v1 + v2;
    assert(v3[0] == 2);
    assert(v3[1] == 4);
    assert(v3[2] == 6);
    std::cout << "Operator + : PASSED" << std::endl;

    v1 += v3;
    assert(v1[0] == 3);
    assert(v1[1] == 6);
    assert(v1[2] == 9);
    std::cout << "Operator += : PASSED" << std::endl;

    //------------------------
    //Test soustraction
    Vec3d v4 = v3 - v1;
    assert(v4[0] == -1);
    assert(v4[1] == -2);
    assert(v4[2] == -3);
    std::cout << "Operator - : PASSED" << std::endl;

    v4 -= v3;
    assert(v4[0] == -3);
    assert(v4[1] == -6);
    assert(v4[2] == -9);
    std::cout << "Operator -= : PASSED" << std::endl;

    //------------------------
    //Test product
    Vec3d v5 = v2*10;
    assert(v5[0] == 10);
    assert(v5[1] == 20);
    assert(v5[2] == 30);
    std::cout << "Operator * : PASSED" << std::endl;

    v5*= 10;
    assert(v5[0] == 100);
    assert(v5[1] == 200);
    assert(v5[2] == 300);
    std::cout << "Operator *= : PASSED" << std::endl;

    //------------------------
    //Test division
    v5 = v3 / 2;
    assert(v5[0] == 1);
    assert(v5[1] == 2);
    assert(v5[2] == 3);
    std::cout << "Operator / : PASSED" << std::endl;

    Vec3d v6 = {12,15,3};
    v6 /= 6;
    assert(v6[0] == 2);
    assert(v6[1] == 2.5);
    assert(v6[2] == 0.5);
    std::cout << "Operator /= : PASSED" << std::endl;

    //------------------------
    //Test Scalar Product
    Vec3d v7 = {2,2,2};
    Vec3d v8 = {1,2,3};
    double resultatScalaire = scalar_product(v7,v8);
    assert(resultatScalaire == 12);
    std::cout << "Function Scalar product : PASSED" << std::endl;

    //------------------------
    //Test V = 0.5*V
    v8 = 0.5*v8;
    assert(v8[0] == 0.5);
    assert(v8[1] == 1);
    assert(v8[2] == 1.5);
    std::cout << "Test V = 0.5*V : PASSED" << std::endl;

    //------------------------
    //Produit Vectoriel
    Vec3d v9 = { 5 ,-6,3};
    Vec3d v10 ={ -2 ,7,4};
    Vec3d v11 = cross(v9,v10);
    assert(v11[0] == -45);
    assert(v11[1] == -26);
    assert(v11[2] == 23);
    std::cout << "Test Cross product : PASSED" << std::endl;

    //------------------------
    //Display Test
    std::cout <<"v11 = " << v11 << std::endl;

	return 0;

}


