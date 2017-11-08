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


	return 0;

}


