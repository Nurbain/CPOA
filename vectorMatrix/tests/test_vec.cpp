#include <iostream>
#include "vector.h"



int main()
{
    /*
    testing::InitGoogleTest(&argc, argv);
    setlocale(LC_CTYPE, "");
    return RUN_ALL_TESTS();
    */
    Vec3d v1 = {1,2,3};
    Vec3d v2 = Vec3d();

    std::cout << "Test Vecteur" << std::endl;
    std::cout << v1[0] << v1[1] << v1[2] << std::endl;
    std::cout << v2[0] << v2[1] << v2[2] << std::endl;

    //std::cout << v1 << std::endl;

	return 0;
}


