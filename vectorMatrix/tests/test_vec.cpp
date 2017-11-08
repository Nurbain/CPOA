#include <iostream>
#include "vector.h"

int main()
{
    //Test Constructeur
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

    v2 = v1;
    assert(v2[0] == 1);
    assert(v2[1] == 2);
    assert(v2[2] == 3);
    std::cout << "Operator = : PASSED" << std::endl;

    bool result = v2==v1;
    Vec3d v2Bis = Vec3d();
    bool resultBis = v2Bis==v1;
    assert(result == 1);
    assert(resultBis == 0);
    std::cout << "Operator == : PASSED" << std::endl;

    Vec3d v3 = v1 + v2;



	return 0;

}


